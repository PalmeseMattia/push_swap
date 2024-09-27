#include <stdlib.h>

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

t_stacks	*new_stacks(int capacity)
{
	t_stacks *result = (t_stacks *)malloc(sizeof(t_stacks));
	if (!result)
		return (NULL);
	result -> a = (t_stack *)malloc(sizeof(t_stack));
	if (!result -> a)
	{
		free(result);
		return (NULL);
	}
	result -> b = (t_stack *)malloc(sizeof(t_stack));
	if (!result -> b)
	{
		free(result -> a);
		free(result);
		return (NULL);
	}
	result -> a -> capacity = capacity;
	result -> b -> capacity = capacity;
	result -> a -> elements = (int *)calloc(capacity, sizeof(int));
	result -> b -> elements = (int *)calloc(capacity, sizeof(int));
	result -> a -> top = 0;
	result -> b -> top = 0;
	return (result);
}

int main()
{
	
}
