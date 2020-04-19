UNITY = ../Unity/src
CFLAGS = -I$(UNITY)
LDLIBS = $(UNITY)/unity.o

.PHONY: all clean

all : list_example list_test

list_example: list.o

list_test: list.o

clean:
	rm -f *.o list list_example list_test
