LIB = stacks.a
CC = gcc
SRC = stacks.c operations.c stack.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(LIB)

$(LIB) : $(OBJ)
	$(AR) -r $@ $?

%.o : %.c
	$(CC) $(FLAGS) -c $?

clean :
	rm *.o
