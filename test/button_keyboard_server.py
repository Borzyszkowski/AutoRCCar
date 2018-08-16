__author__ = 'Borzyszkowski'

import socket
import time


class KeyboardStreaming(object):
    def __init__(self, host, port):

        self.server_socket = socket.socket()
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind((host, port))
        self.server_socket.listen(0)
        self.connection, self.client_address = self.server_socket.accept()
        self.host_name = socket.gethostname()
        self.host_ip = socket.gethostbyname(self.host_name)
        self.streaming()

    def type(self):
        prediction = input("Type F,B,R,L or S: ")
        prediction = prediction.lower()
        print(prediction)
        return prediction

    def streaming(self):

        try:
            print("Host: ", self.host_name + ' ' + self.host_ip)
            print("Connection from: ", self.client_address)
            start = time.time()

            while True:
                prediction = type(self.connection.send(str(prediction)))
                time.sleep(0.01)
                print("Move: % " % prediction)

                # test for 10 seconds
                if time.time() - start > 10:
                    break
        finally:
            self.connection.close()
            self.server_socket.close()



if __name__ == '__main__':
    h, p = ('172.20.10.4', 65530)
    KeyboardStreaming(h, p)
