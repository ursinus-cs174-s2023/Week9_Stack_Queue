CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.cpp

driver: linkedlist.o driver.cpp
	$(CC) $(CFLAGS) -o driver driver.cpp linkedlist.o

clean:
	rm *.o driver