CC = g++
CFLAGS = -g
OUTPUT = main

all: build run clean

check: $(OUTPUT)
	valgrind ./$(OUTPUT)

debug: $(OUTPUT)
	gdb ./$(OUTPUT)

ERROR: main.cpp
	$(CC) $(CFLAGS) main.cpp -DSEGFAULT -o $(OUTPUT)

build: main.cpp
	@echo ================
	@echo Build program
	@echo ================
	$(CC) $(CFLAGS) main.cpp -o $(OUTPUT)

clean:
	@echo ================
	@echo Clean everything
	@echo ================
	@rm -f *.o $(OUTPUT)

run: $(OUTPUT)
	@echo ================
	@echo Run program
	@echo ================
	./$(OUTPUT)

.PHONY: run clean check 

# make clean - usunie niepotrzebne pliki
# make run - uruchomi program
# make check  - uruchomi valgrind ./main
# make debug - uruchomi gdb ./main
# make ERROR - skompiluje program z flagą -DSEGFAULT 
# make all - komiluje, uruchamia i czyści.