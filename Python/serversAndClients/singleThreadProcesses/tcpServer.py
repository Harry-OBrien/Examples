import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind(("0.0.0.0", 1338))
serversocket.listen(10)

while True:
	conn, addr = serversocket.accept()
	conn.send(("Do You want to play a game?\n"))
	received = conn.recv(1024)
	print(received)

serversocket.close()
