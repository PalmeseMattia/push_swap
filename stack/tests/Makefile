SRCS := $(wildcard *.c)

EXECS := $(SRCS:.c=)

all : $(EXECS)

%: %.c
	gcc $< ../stack.c -o $@

clean:
	rm -f $(EXECS)

run: all
	@for exec in $(EXECS); do echo "Running $$exec...";./$$exec; done

.PHONY: all clean run
