import socket


serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

serverSocket.bind(('', 9986))
serverSocket.listen(10)

while True:
    connection, address = serverSocket.accept()
    data = connection.recv(1024)

    if len(data) > 0:
        print("Got connection from " + str(address))
        print("\nreceived: " + str(data))
        
    connection.send(b"Thanks for connecting! Bye now!")
    connection.close()

    break
serverSocket.close()
