VERSION = 0.2
CC			= clang
CFLAGS  = -Wall -O3  -march=native -Wpedantic -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o primes.o primebench.o
SRC = $(OBJ:%.o=%.c) main.c
HDR = $(OBJ:%.o=%.h)

BIN = sprimes

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	rm -rfv $(BIN) $(OBJ)

