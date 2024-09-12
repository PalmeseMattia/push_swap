LIB = stacks.a
CC = gcc
SRC = stacks.c operations.c stack.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

all : $(LIB)

$(LIB) : $(OBJ)
	$(AR) -r $@ $?

%.o : %.c
	$(CC) $(FLAGS) -c $?

clean :
	rm *.o

fclean : clean
	rm $(LIB)

re : fclean all
