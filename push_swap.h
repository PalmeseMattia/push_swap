#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"
typedef struct s_stack
{
	int	*elements;
	int	capacity;
	int	top;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

int			ft_strisnum(char *str);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

t_stacks	*new_stacks(int capacity);
void		push(t_stacks *s, int num);

void	sort_four_five(t_stacks *s);

#endif
