__author__ = 'Borzyszkowski'

import numpy as np
import cv2
import socket


class VideoStreamingTest(object):
    def __init__(self, host, port):

        self.server_socket = socket.socket()
<<<<<<< HEAD
        self.server_socket.bind(('172.20.10.4',65533))
=======
        self.server_socket.bind((host, port))
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
        self.server_socket.listen(0)
        self.connection, self.client_address = self.server_socket.accept()
        self.connection = self.connection.makefile('rb')
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
            print("Streaming...")
            print("Press 'q' to exit")

<<<<<<< HEAD
=======
            # need bytes here
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
            stream_bytes = b' '
            while True:
                stream_bytes += self.connection.read(1024)
                first = stream_bytes.find(b'\xff\xd8')
                last = stream_bytes.find(b'\xff\xd9')
                if first != -1 and last != -1:
                    jpg = stream_bytes[first:last + 2]
                    stream_bytes = stream_bytes[last + 2:]
<<<<<<< HEAD
                    image = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8),  cv2.IMREAD_GRAYSCALE)
                    #image = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8),  cv2.IMREAD_COLOR)
=======
                    image = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
>>>>>>> 7303db8acd948e2a90c758bd779e8af3920668fd
                    cv2.imshow('image', image)

                    if cv2.waitKey(1) & 0xFF == ord('q'):
                        break
        finally:
            self.connection.close()
            self.server_socket.close()


if __name__ == '__main__':
    # host, port
    h, p = "192.168.1.100", 8000
    VideoStreamingTest(h, p)
