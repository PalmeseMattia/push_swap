STACKLIB = stack/stacks.a
STACKLIB_DIR = ./stack
SRC = main.c quicksort.c

all : main.c
	gcc -g $(SRC) $(STACKLIB) -o main

main.c : $(STACKLIB)
	
$(STACKLIB) :
	@$(MAKE) -C $(STACKLIB_DIR)

clean :
	rm -f *.o

fclean : clean
	rm main

re_lib :
	@$(MAKE) re -C $(STACKLIB_DIR)

re : re_lib fclean all
