CC=gcc
CFLAGS=-Wall -Wextra -std=c99
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

all: column dictionary scanner main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.c: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

column: $(OBJS)	
	$(CC) $(CFLAGS) $^ -o $@ 
dictionary: $(OBJS)	
	$(CC) $(CFLAGS) $^ -o $@ 
scanner: $(OBJS)	
	$(CC) $(CFLAGS) $^ -o $@ 
main: $(OBJS)	
	$(CC) $(CFLAGS) $^ -o $@ 

run-tests: column dictionary scanner main
	./column ./tests/column_test.txt
	./dictionary ./tests/dictionary_test.txt
	./scanner ./tests/scanner_test.txt

test: run-tests

integration_test:	
	./main ./tests/integration_test.txt

.PHONY: test integration_test