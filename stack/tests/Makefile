SRCS := $(wildcard *.c)

FILES := ../stack.c ../twostack.c

FLAGS := -I../../includes

EXECS := $(SRCS:.c=)

all : $(EXECS)

%: %.c
	gcc $(FLAGS) $< $(FILES) -o $@

clean:
	rm -f $(EXECS)

run: all
	@for exec in $(EXECS); do echo "Running $$exec...";./$$exec; done

.PHONY: all clean run
