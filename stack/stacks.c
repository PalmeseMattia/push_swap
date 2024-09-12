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
	result -> n_operations = 0;
	result -> orderliness = 0;
	result -> operations = NULL;
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
	dst -> orderliness = src -> orderliness;
	dst -> n_operations = src -> n_operations;
}

void add_operation(t_stacks *s, char *op)
{
	if (!s -> operations)
		s -> operations = (char **)malloc(10 * sizeof(char *));
	if (s -> n_operations % 10 == 0)
			s -> operations = realloc(s -> operations, s -> n_operations + 10);
	s -> operations[s -> n_operations] = (char *)malloc((strlen(op) + 1) * sizeof(char));
	strcpy(s -> operations[s -> n_operations++], op);
}

void	print_stacks(t_stacks *stacks)
{
	printf("Stack A: ");
	print_stack(stacks -> a);
	printf("Stack B: ");
	print_stack(stacks -> b);
	printf("Orderliness: %d\n", stacks -> orderliness);
	printf("Number of operations: %d\n", stacks -> n_operations);
	printf("Operations: [");
	for(int i = 0; i < stacks -> n_operations - 1; i++) {
		printf("%s, ", stacks -> operations[i]);
	}

	printf("%s]\n", stacks -> operations[stacks -> n_operations - 1]);
}
