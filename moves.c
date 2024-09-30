#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks -> a -> elements[0];
	stacks -> a -> elements[0] = stacks -> a -> elements[1];
	stacks -> a -> elements[1] = tmp;
	write(1, "sa\n", 3);
}
