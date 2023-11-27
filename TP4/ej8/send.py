import serial

ser = serial.Serial('/dev/ttyS0', 9600)  # Ajusta el puerto y la velocidad de baudios

while True:
    ser.write(b'Hola desde Raspberry Pi 1\n')
