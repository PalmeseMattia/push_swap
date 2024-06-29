SRCS := $(wildcard *.c)

FILES := ../stack.c ../twostack.c ../operations.c

FLAGS := -I../../includes

EXECS := $(SRCS:.c=)

all : $(EXECS)

%: %.c
	gcc $(FLAGS) $< $(FILES) -o $@

clean:
	rm -f $(EXECS)

run: all
	@for exec in $(EXECS); do echo "\033[1mRUNNING $$exec\033[0m";./$$exec; done

.PHONY: all clean run
