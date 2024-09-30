#include "push_swap.h"

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

int	is_sorted(int *array, int size)
{
	while(size > 0)
	{
		if (array[size - 1] < array[size - 2])
			return (0);
		size--;
	}
	return (1);
}

void check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisnum(argv[i]))
		{
			ft_printf("Error: Please provide strictly numerical values\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	if (argc < 2) {
		exit(EXIT_SUCCESS);
	}
	check_input(argc, argv);
	stacks = new_stacks(argc - 1);
	i = 1;
	while (i < argc)
	{
		stacks -> a -> elements[i - 1] = ft_atoi(argv[i]);
		i++;
	}

	/* To leverage the radix sort we do a rank transformation,
	 * to get smaller binaries
	 */
	i = 0;
	int j;
	int rank;
	int *new_elements = (int *)malloc(stacks -> a -> capacity * sizeof(int));
	while (i < stacks -> a -> capacity)
	{
		rank = 0;
		j = 0;
		while(j < stacks -> a -> capacity)
		{
			if (stacks -> a -> elements[i] > stacks -> a -> elements[j])
				rank++;
			j++;
		}
		new_elements[i] = rank;
		i++;
	}
	i = 0;
	while (i < stacks -> a -> capacity)
	{
		stacks -> a -> elements[i] = new_elements[i];
		i++;
	}
	//Print array to be safe :)
	for (int i = 0; i < stacks -> a -> capacity; i++)
	{
		ft_printf("%d\n", stacks -> a -> elements[i]);
	}

	return (0);
}
