
CFLAGS=-std=c17 -Wall -Wextra -Werror

all:
	gcc example.c dynamic-array.c -o run $(CFLAGS)