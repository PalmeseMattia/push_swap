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
	int	i;

	i = 0;
	if (stacks)
	{
		free_stack(stacks -> a);
		free_stack(stacks -> b);
		while (i < stacks -> n_operations) {
			if (stacks -> operations[i]) {
				free(stacks -> operations[i]);
				stacks->operations[i] = NULL;
			}
			i++;
		}
		free(stacks -> operations);
		free(stacks);
	}
}

void	free_operations(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks -> operations)
	{
		while (i < stacks -> n_operations) {
			free(stacks -> operations[i]);
			i++;
		}
		free(stacks -> operations);
		stacks -> operations = NULL;
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
	free_operations(dst);
	dst -> n_operations = src -> n_operations;
	dst -> operations = (char **)malloc(src -> n_operations * sizeof(char *));
	if (!dst -> operations) {
		perror("Failed to allocate operations array in copy_stacks");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < src -> n_operations; i++) {
		char *op = src -> operations[i];
		dst -> operations[i] = (char *)malloc((strlen(op) + 1) * sizeof(char));
		strcpy(dst -> operations[i], op);
	}
}

void add_operation(t_stacks *s, char *op)
{
	s -> operations = (char **)realloc(s -> operations, (s -> n_operations + 1) * sizeof(char *));
	s -> operations[s -> n_operations] = (char *)malloc((strlen(op) + 1) * sizeof(char));
	strcpy(s -> operations[s -> n_operations], op);
	s -> n_operations++;
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
	if (stacks -> operations)
	{
		for(int i = 0; i < stacks -> n_operations - 1; i++) {
			printf("%s, ", stacks -> operations[i]);
		}
		printf("%s", stacks -> operations[stacks -> n_operations - 1]);
	}
	printf("]\n");
}

/*
 * This function will free the operations array and 
 * set the orderliness to 0.
 */
void	empty_stack(t_stacks *stacks)
{
	free_operations(stacks);
	stacks -> orderliness = 0;
}

int equal(t_stacks *s1, t_stacks *s2)
{
	if (s1 -> orderliness != s2 -> orderliness)
		return 0;
	for (int i = 0; i < s1 -> a -> top; i++) {
		if (s1 -> a -> elements[i] != s2 -> a -> elements[i])
			return 0;
	}
	for (int i = 0; i < s1 -> b -> top; i++) {
		if (s1 -> b -> elements[i] != s2 -> b -> elements[i])
			return 0;
	}
	return 1;
}
