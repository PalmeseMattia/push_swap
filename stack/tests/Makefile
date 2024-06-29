SRCS := $(wildcard *.c)

FILES := ../stack.c ../twostack.c

EXECS := $(SRCS:.c=)

all : $(EXECS)

%: %.c
	gcc $< $(FILES) -o $@

clean:
	rm -f $(EXECS)

run: all
	@for exec in $(EXECS); do echo "Running $$exec...";./$$exec; done

.PHONY: all clean run
