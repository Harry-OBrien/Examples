import socket

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect(('192.168.0.35', 80))

clientSocket.send("Do you want to play a game?\n")

received = clientSocket.recv(1024)
print(received)

clientSocket.close()
