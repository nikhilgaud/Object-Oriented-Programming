#Compiler
CC = g++

#Compiler flags
CFLAGS = -c -std=c++11 -g -Wall

#target name
all : a.out

a.out : BufferFile.o StreamIO.o main.o
	$(CC) BufferFile.o StreamIO.o main.o -o a.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

StreamIO.o : StreamIO.cpp
	$(CC) $(CFLAGS) StreamIO.cpp

BufferFile.o : BufferFile.cpp
	$(CC) $(CFLAGS) BufferFile.cpp

clean:
	rm *.o a.out
