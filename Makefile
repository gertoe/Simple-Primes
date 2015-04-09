VERSION = 0.1
CC			= /usr/bin/clang
CFLAGS  = -Wimplicit-function-declaration -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o primetest.o primebench.o
SRC = $(OBJ:%.o=%.c) primes.c
HDR = $(OBJ:%.o=%.h)

BIN = sprimes

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	rm $(BIN) $(OBJ)
