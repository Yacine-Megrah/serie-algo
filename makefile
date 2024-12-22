CC = gcc
SRCS ?= test
libs ?= -lm

define build_rule
$(1): src/$(1).c | bin
	$(CC) $$< -o bin/$$@.exe $(libs)
endef

$(foreach src, $(SRCS), $(eval $(call build_rule,$(src))))

all: $(SRCS)

bin:
	mkdir -p bin

clean:
	rm -f bin/*.exe