VERSION = 0.1
CC			= /usr/bin/clang
CFLAGS  = -Wint-conversion -Wimplicit-function-declaration -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o primes.o primebench.o
SRC = $(OBJ:%.o=%.c) main.c
HDR = $(OBJ:%.o=%.h)

BIN = sprimes

prog: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	rm $(BIN) $(OBJ)
