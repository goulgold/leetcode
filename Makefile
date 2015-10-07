DEBUG := 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -I . -O0
else
	CFLAGS := -I . -O2
endif
CC := g++
FLAGC11 := -std=c++11
UTIL_DIR := util

PROGS_SRC := $(wildcard *.cc)
PROGS := $(patsubst %.cc,%,$(PROGS_SRC))

all: $(PROGS)

$(PROGS): % : %.cc $(UTIL_DIR)/util.h $(UTIL_DIR)/util.cc
	@echo CXX $<
	@$(CC) $(CFLAGS) $(FLAGC11) $< $(UTIL_DIR)/util.cc -o $@ 

.PHONY: clean
clean:
	rm -f $(PROGS)
