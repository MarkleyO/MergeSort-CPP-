# Control Variables
CC = g++
CFLAGS = -Wall -g

merge: mergesort.o
	$(CC) $(CFLAGS) -o merge mergesort.o

mergesort.o: mergesort.cpp
	$(CC) $(CFLAGS) -c mergesort.cpp

clean:
	$(RM) merge mergesort.o
