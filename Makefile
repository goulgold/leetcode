DEBUG = 1
ifeq ($(DEBUG), 1)
	CFLAGS = -g -I . -O2
else
	CFLAGS = -I . -O2
endif
CC = g++
FLAGC11 = -std=c++11

PROGS = twosum\
	addTwoNumbers\
	longestSubstring

all: $(PROGS) util.o

$(PROGS): util.o

twosum: twoSum.o
	$(CC) -o twosum twoSum.o util.o

twoSum.o: twoSum.h
	$(CC) -c twoSum.cc $(CFLAGS) $(FLAGC11)

addTwoNumbers: addTwoNumbers.o
	$(CC) -o addTwoNumbers addTwoNumbers.o $(CFLAGS) $(FLAGC11)

addTwoNumbers.o: addTwoNumbers.cc addTwoNumbers.h
	$(CC) -c addTwoNumbers.cc $(CFLAGS) $(FLAGC11)

longestSubstring: longestSubstring.o
	$(CC) -o longestSubstring longestSubstring.o $(CFLAGS) $(FLAGC11)

longestSubstring.o: longestSubstring.cc longestSubstring.h
	$(CC) -c longestSubstring.cc $(CFLAGS) $(FLAGC11)

util.o: util.cc util.h
	$(CC) -c util.cc $(CFLAGS) $(FLAGC11)

.PHONY: clean
clean:
	rm -f *.o $(PROGS)
