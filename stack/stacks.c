#include "stack.h"

t_stacks	*create_stacks(int capacity)
{
	t_stacks	*result;

	result = (t_stacks *)malloc(sizeof(t_stacks));
	if (result == NULL)
		return (NULL);
	result -> a = create_stack(capacity);
	if (result -> a == NULL)
	{
		free(result);
		return (NULL);
	}
	result -> b = create_stack(capacity);
	if (result -> b == NULL)
	{
		free_stack(result -> a);
		free(result);
		return (NULL);
	}
	return (result);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks)
	{
		free_stack(stacks -> a);
		free_stack(stacks -> b);
		free(stacks);
	}
}

void copy_stacks(t_stacks *src, t_stacks *dst)
{
	for (int i = 0; i < dst -> a -> capacity; i++) {
		dst -> a -> elements[i] = src -> a -> elements[i];
		dst -> b -> elements[i] = src -> b -> elements[i];
	}
	dst -> a -> top = src -> a -> top;
	dst -> b -> top = src -> b -> top;
}

void	print_stacks(t_stacks *stacks)
{
	printf("Stack A: ");
	print_stack(stacks -> a);
	printf("Stack B: ");
	print_stack(stacks -> b);
}
