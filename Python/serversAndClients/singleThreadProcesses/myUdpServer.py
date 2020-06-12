
import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serversocket.bind(("0.0.0.0", 1337))

while True:
        data, addr = serversocket.recvfrom(1024)
        print(data)

