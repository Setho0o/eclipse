CC = gcc
CFLAGS = -Wall -g -I include 
LDFLAGS = 
SRC = $(wildcard *.c) $(wildcard src/*.c)
OUT = eclipse

default: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)  $(LDFLAGS)
	./$(OUT)

build: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)  $(LDFLAGS)

clean:
	rm -f $(OUT)
