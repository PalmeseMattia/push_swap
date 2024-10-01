#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks -> a -> elements[0];
	stacks -> a -> elements[0] = stacks -> a -> elements[1];
	stacks -> a -> elements[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks -> b -> elements[0];
	stacks -> b -> elements[0] = stacks -> b -> elements[1];
	stacks -> b -> elements[1] = tmp;
	write(1, "sb\n", 3);
}

//Rotate UP
void	ra(t_stacks *stacks)
{
	int	tmp;
	int	i;

	tmp = stacks -> a -> elements[0];
	i = 0;
	while(i < stacks -> a -> top - 1)
	{
		stacks -> a -> elements[i] = stacks -> a -> elements[i + 1]; 
		i++;
	}
	stacks -> a -> elements[i] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stacks *stacks)
{
	int	last;
	int	i;

	last = stacks -> a -> elements[stacks -> a -> top - 1];
	i = stacks -> a -> top - 1;
	while (i > 0)
	{
 		stacks -> a -> elements[i] = stacks -> a -> elements[i - 1];
		i--;
	}
	stacks -> a -> elements[0] = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	int	last;
	int	i;

	last = stacks -> b -> elements[stacks -> b -> top - 1];
	i = stacks -> b -> top - 1;
	while (i > 0)
	{
 		stacks -> b -> elements[i] = stacks -> b -> elements[i - 1];
		i--;
	}
	stacks -> b -> elements[0] = last;
	write(1, "rrb\n", 4);
}

void	rb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	tmp = stacks -> b -> elements[0];
	i = 0;
	while(i < stacks -> b -> top - 1)
	{
		stacks -> b -> elements[i] = stacks -> b -> elements[i + 1]; 
		i++;
	}
	stacks -> b -> elements[i] = tmp;
	write(1, "rb\n", 3);
}

