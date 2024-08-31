STACKLIB = stack/stacks.a
STACKLIB_DIR = ./stack

all : main.c
	gcc main.c $(STACKLIB) -o main

main.c : $(STACKLIB)
	
$(STACKLIB) :
	@$(MAKE) -C $(STACKLIB_DIR)
