LIB = stacks.a
CC = gcc
SRC = stacks.c operations.c stack.c
OBJ = $(SRC:.c=.o)

all : $(LIB)

$(LIB) : $(OBJ)
	$(AR) -r $@ $?

%.o : %.c
	$(CC) -c $?

clean :
	rm *.o
