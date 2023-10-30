#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BCM2835_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)
volatile unsigned int *gpio; //Pointer to base of gpio
#define GPLEV0 (* (volatile unsigned int *) (gpio + 13))
#define BLOCK_SIZE (4*1024)
void pioInit(){
int mem_fd;
void *reg_map;
// /dev/mem is a psuedo-driver for accessing memory in Linux
mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
reg_map = mmap(
NULL, // Address at which to start local mapping (null = don't-care)
BLOCK_SIZE, // 4KB mapped memory block
PROT_READ|PROT_WRITE, // Enable both reading and writing to the mapped memory
MAP_SHARED, // Nonexclusive access to this memory
mem_fd, // Map to /dev/mem
GPIO_BASE); // Offset to GPIO peripheral
gpio = (volatile unsigned *)reg_map;
close(mem_fd);
}
#define GPFSEL ((volatile unsigned int *) (gpio + 0))
#define GPSET ((volatile unsigned int *) (gpio + 7))
#define GPCLR ((volatile unsigned int *) (gpio + 10))
#define GPLEV ((volatile unsigned int *) (gpio + 13))
#define INPUT 0
#define OUTPUT 1
void pinMode(int pin, int function) {
int reg = pin/10;
int offset = (pin%10)*3;
GPFSEL[reg] & = ~((0b111 & ~function) << offset);
GPFSEL[reg] | = ((0b111 & function) << offset);
}
void digitalWrite(int pin, int val) {
int reg = pin / 32;
int offset = pin % 32;
if (val) GPSET[reg] = 1 << offset;
else GPCLR[reg] = 1 << offset;
}
int digitalRead(int pin) {
int reg = pin / 32;
int offset = pin % 32;
return (GPLEV[reg] >> offset) & 0x00000001;
}

#define UART_BASE  0x3F201000 // Base address for UART
#define UART_DR *(volatile unsigned *)(UART_BASE)
#define UART_FR *(volatile unsigned *)(UART_BASE + 0x18)
#define UART_IBRD *(volatile unsigned *)(UART_BASE + 0x24)
#define UART_FBRD *(volatile unsigned *)(UART_BASE + 0x28)
#define UART_LCRH *(volatile unsigned *)(UART_BASE + 0x2C)
#define UART_CR *(volatile unsigned *)(UART_BASE + 0x30)

void uartInit(int baud) {
    uint fb = 12000000 / baud; // 3 MHz UART clock
    pinMode(14, ALT0); // TX
    pinMode(15, ALT0); // RX
    UART_IBRD = fb >> 6; // 6 Fract, 16 Int bits of BRD
    UART_FBRD = fb & 63;
    UART_LCRH = (3 << 5); // 8 Data, 1 Stop, no Parity
    UART_CR = (1 << 0) | (1 << 8) | (1 << 9); // Enable uart, TX, RX
}

char getCharSerial(void) {
    while (UART_FR & (1 << 4)); // Wait until data is available
    return UART_DR; // Return char from serial port
}

void putCharSerial(char c) {
    while (UART_FR & (1 << 5)); // Wait until ready to transmit
    UART_DR = c; // Send char to serial port
}

#define MAX_STR_LEN 80

void getStrSerial(char *str) {
    int i = 0;
    do { // Read an entire string until
        str[i] = getCharSerial(); // Carriage return
    } while ((str[i++] != '\r') && (i < MAX_STR_LEN));
    str[i - 1] = 0; // Null-terminate the string
}

void putStrSerial(char *str) {
    int i = 0;
    while (str[i] != 0) { // Iterate over string
        putCharSerial(str[i++]); // Send each character
    }
}