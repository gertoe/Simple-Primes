VERSION = 0.1
CC			= /usr/bin/clang
CFLAGS  = -Wimplicit-function-declaration -DVERSION=\"$(VERSION)\"
LDFLAGS = -lm

OBJ = main.o primetest.o primebench.o
SRC = $(OBJ:%.o=%.c) main.c
HDR = $(OBJ:%.o=%.h)

BIN = prime

prog: $(OBJ)
  $(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
  rm $(BIN) $(OBJ)
