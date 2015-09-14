DEBUG = 1
ifeq ($(DEBUG), 1)
	CFLAGS = -g -I . -O2
else
	CFLAGS = -I . -O2
endif
CC = g++
FLAGC11 = -std=c++11

PROGS = testbin

OBJECTS = main.o twoSum.o util.o

all: $(PROGS)

testbin: $(OBJECTS)
	$(CC) -o testbin $(OBJECTS)

main.o: main.cc
	$(CC) -c main.cc $(CFLAGS) $(FLAGC11)

twoSum.o: twoSum.h twoSum.cc
	$(CC) -c twoSum.cc $(CFLAGS) $(FLAGC11)

util.o: util.cc util.h
	$(CC) -c util.cc $(CFLAGS) $(FLAGC11)

.PHONY: clean
clean:
	rm -f testbin $(OBJECTS)
