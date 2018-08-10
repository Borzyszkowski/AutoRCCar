__author__ = 'Borzyszkowski'

import socket
import time


class SensorStreamingTest(object):
    def __init__(self, host, port):

        self.server_socket = socket.socket()
<<<<<<< HEAD
        self.server_socket.bind(('172.20.10.4', 65534))
=======
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind((host, port))
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
        self.server_socket.listen(0)
        self.connection, self.client_address = self.server_socket.accept()
        self.host_name = socket.gethostname()
        self.host_ip = socket.gethostbyname(self.host_name)
        self.streaming()

    def streaming(self):

        try:
<<<<<<< HEAD
=======
            print("Host: ", self.host_name + ' ' + self.host_ip)
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
            print("Connection from: ", self.client_address)
            start = time.time()

            while True:
                sensor_data = float(self.connection.recv(1024))
                print("Distance: %0.1f cm" % sensor_data)
<<<<<<< HEAD
                #testing for 10 seconds
                #if time.time() - start > 10:
                   # break
=======

                # test for 10 seconds
                if time.time() - start > 10:
                    break
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
        finally:
            self.connection.close()
            self.server_socket.close()


if __name__ == '__main__':
    h, p = "192.168.1.100", 8002
    SensorStreamingTest(h, p)
