OUT = push_swap
SRCS = main.c ft_strisnum.c moves.c moves_2.c stacks.c sort.c
LIBFT = libft.a

all : $(LIBFT)
	gcc $(SRCS) -lft -Llibft -g -o push_swap

$(LIBFT):
	make -C ./libft

libclean:
	make clean -C ./libft

libfclean:
	make fclean -C ./libft

clean: libclean
	rm -rf *.o

fclean: clean libfclean
	rm -f $(OUT)

re: fclean all

