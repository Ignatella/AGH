OBJS = $(wildcard src/*.cpp)
CC = g++
LFLAGS = -Wall -Iinclude -pedantic 

all: clean main test

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main  

test: 
	./main

pack: 
	tar -czvf file.tar.gz ./*

.PHONY: clean

clean: 
	rm -f *.o main *.tar.gz
