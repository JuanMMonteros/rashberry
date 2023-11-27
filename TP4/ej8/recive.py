import serial

ser = serial.Serial('/dev/serial0', 9600)  # Ajusta el puerto y la velocidad de baudios

while True:
    received_data = ser.readline()
    print(received_data)
