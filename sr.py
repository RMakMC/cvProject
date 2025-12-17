import serial
ser = serial.Serial('COM4', baudrate=9600, timeout=1)
ser.write(b'command')
data = ser.readline()
ser.close()
