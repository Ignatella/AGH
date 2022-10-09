OBJS = $(wildcard src/*.cpp)
CC = g++
LFLAGS = -Wall -Iinclude -pedantic 

all: clean main test

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main  

test: 
	./main

.PHONY: clean

clean: 
	rm -f *.o main
