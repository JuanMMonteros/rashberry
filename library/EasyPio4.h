#include <sys/mman.h>
#define BCM2835_PERI_BASE 0xFE000000
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

void uartInit ( int baud ) {
 uintfb = 12000000/ baud ; // 3 MHz UART c l o c k4 pinMode (14 , ALT0) ; // TX
 pinMode (15 , ALT0) ; // RX
 pinMode (14 , ALT0) ; //Tx
 UART_IBRD = f b >> 6 ; // 6 f r e c i o n a r i o s y 16
 UART_FBRD = f b & 6 3;
 UART_LCRHbits.WLEN = 3 ; // 8N1 , s i n FIFO y s i n

UART_CRbits .UARTEN = 1 ; // Enable u a r t
 }

 char getChar(void) {
while (UART_Frbits.RXFE) ; // Espera h a s t a t e n e r un
     dato −> RXFE==0
return UART_DRbits.DATA;
}

void putChar( char c ) {
while (!UART_Frbits.TXFE) ; // Espera h a s t a poder
enviar −> TXFE==1
UART_DRbits.DATA = c ;
}

#define MAX_STR_LEN 80
3
4 void getStr(char ∗str) {
5 int i=0;
6 do{
7 str[i] = getChar();
8 } while ( ( str[i ++]!= '\r' ) && (i<MAX_STR_LEN));
9 str[i−1]=0;
10}
11
12 void putStr( char ∗str) {
13 int i = 0 ;
14 while (str[i]!=0){
15 putChar(str[ i++]);
16 }
17 }


