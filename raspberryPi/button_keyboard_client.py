import serial
from socket import *
import time


def type ():
    prediction=input("Type F,B,R,L or S: ")
    prediction=prediction.lower()
    print(prediction)
    return prediction

def steer(prediction, serial_port):
    if prediction == 'f':
        serial_port.write(chr(1).encode())
        print("Forward")

    elif prediction == 'b':
        serial_port.write(str(2).encode())
        print("Backward")

    elif prediction == 'l':
        serial_port.write(str(3).encode())
        print("Left")

    elif prediction == 'r':
        serial_port.write(str(4).encode())
        print("Right")

    elif prediction == 's':
        serial_port.write(str(5).encode())
        print("Stop")

    else:
        serial_port.write(str(5).encode())

def start():
    try:
        serial_port = serial.Serial(port='COM5', baudrate=9600, timeout=0)
    except serial.SerialException as e:
        print("could not open serial port.")
        return
    return serial_port


# create a socket and bind socket to the host
client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect(('172.20.10.4', 65530))


try:
    while True:
        prediction = client_socket.recv(str(prediction))
        print ("Move: % " % prediction)
        # send data to the host every 0.01 sec
        time.sleep(0.01)
finally:
    client_socket.close()
    GPIO.cleanup()


def main(serial_port):
    steer(prediction, serial_port)


serial_port=start()
while True:
    main(serial_port)
