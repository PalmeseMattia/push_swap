#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 10

typedef struct s_stack
{
	int	*elements;
	int	capacity;
	int	top;
}	t_stack;

t_stack	*create_stack(unsigned int n);
int	is_empty(t_stack *stack);
int is_full(t_stack *stack);
void push(t_stack *stack, int n);
void pop(t_stack *stack);
int seek(t_stack *stack);

#endif
