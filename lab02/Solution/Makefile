CC=gcc
CFLAGS=-Wall -std=c99 -g

all: Bit_Operation

Bit_Operation: bit_ops.o test_bit_ops.o
	$(CC) -o bit_ops bit_ops.o test_bit_ops.o

bit_ops.o: bit_ops.c bit_ops.h
	$(CC) $(CFLAGS) -c bit_ops.c

test_bit_ops.o: test_bit_ops.c bit_ops.h
	$(CC) $(CFLAGS) -c test_bit_ops.c

clean:
	rm bit_ops bit_ops.o test_bit_ops.o
