import serial
import time
import serial.tools.list_ports
ports = list(serial.tools.list_ports.comports())
def find_arduino():
    arduino_ports = []
    for port in ports:
        if 'Arduino' in port.description or port.vid == 0x2341:
            return port.device
print(find_arduino())    
ser = serial.Serial(find_arduino(), 9600, timeout = 0.5)

