#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define BUFFER_SIZE 10

typedef struct s_stack
{
	int	*elements;
	int	capacity;
	int	top;
}	t_stack;

typedef struct s_twostack
{
	t_stack	*a;
	t_stack *b;
}	t_twostack;

t_stack		*create_stack(unsigned int n);
t_twostack	*create_twostack(int capacity);
int			is_empty(t_stack *stack);
int			is_full(t_stack *stack);
void		push(t_stack *stack, int n);
void		pop(t_stack *stack);
int			seek(t_stack *stack);
void		print_stack(t_stack *stack);
void		free_stack(t_stack *stack);
void		free_twostack(t_twostack *twostack);
void		print_twostack(t_twostack *twostack);

// OPERATIONS
void		sa(t_twostack *twostack);
void		sb(t_twostack *twostack);
void		ss(t_twostack *twostack);
void		pa(t_twostack *twostack);

#endif
