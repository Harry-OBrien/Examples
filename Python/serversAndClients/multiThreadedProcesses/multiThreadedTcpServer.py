import socket
import thread

def handler(clientsock, addr):
	clientsock.send("Do you want to play a game?\n")
	data = clientsock.recv(1024)
	print(repr(addr) + "said: " + data)
	clientsock.close()
	print(repr(addr) + " connection ended.")

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind(("0.0.0.0", 1337))
serversocket.listen(10)

while True:
	print("Server Listening...")
	clientsock, addr = serversocket.accept()
	thread.start_new_thread(handler, (clientsock, addr))
