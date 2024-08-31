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

typedef struct s_stacks
{
	t_stack	*a;
	t_stack *b;
}	t_stacks;

t_stack		*create_stack(unsigned int n);
t_stacks	*create_stacks(int capacity);

///STACK OPERATIONS
int			is_empty(t_stack *stack);
int			is_full(t_stack *stack);
void		push(t_stack *stack, int n);
void 		push_back(t_stack *stack, int n);
void		pop(t_stack *stack);
int			peek(t_stack *stack);
void		print_stack(t_stack *stack);
void		free_stack(t_stack *stack);
void		free_stacks(t_stacks *stacks);
void		print_stacks(t_stacks *stacks);

// OPERATIONS
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rra(t_stacks *stacks);

#endif
