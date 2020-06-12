import socket

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
clientSocket.sendto("UDP is connectionless...\n", ("127.0.0.1", 1337))
