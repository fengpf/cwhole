
objs = client server hostinfo adder tiny *.o

CC = gcc -pthread


all: clean client server hostinfo adder tiny

client: client.c
	$(CC) client.c -o client.o

server: server.c
	$(CC)  server.c -o server.o
	
hostinfo: hostinfo.c
	$(CC)  hostinfo.c -o hostinfo.o
	
adder: adder.c
	$(CC)  adder.c -o adder.o
	
tiny: tiny.c
	$(CC)  tiny.c -o tiny.o
	
clean:
	rm -rf $(objs)