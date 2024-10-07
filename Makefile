OUT = push_swap
SRCS = src/main.c src/ft_strisnum.c src/moves.c \
	   src/moves_2.c src/stacks.c src/sort.c \
	   src/utils.c

LIBFT = libft.a
LIBFT_DIR = ./libs/libft

FLAGS = -Wall -Wextra -Werror -g

all : $(LIBFT)
	gcc $(SRCS) -lft -L$(LIBFT_DIR) $(FLAGS) -o push_swap

$(LIBFT):
	make -C $(LIBFT_DIR)

libclean:
	make clean -C $(LIBFT_DIR)

libfclean:
	make fclean -C $(LIBFT_DIR)

clean: libclean
	rm -rf *.o

fclean: clean libfclean
	rm -f $(OUT)

re: fclean all

