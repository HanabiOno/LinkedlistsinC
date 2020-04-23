CC = gcc

.PHONY: all clean

all : bst_example

bst_example: bst_example.c
	$(CC) -o bst_example bst_example.c 

clean:
	rm -f *.o BT bst_example
