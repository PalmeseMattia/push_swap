#include "push_swap.h"


void	sort_three(t_stacks *stacks);


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
		push(stacks,  ft_atoi(argv[i]));
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
	ft_printf("TOP: %d\n", stacks -> a -> top);

	//Sort 2 elements
	int capacity = stacks -> a -> capacity;
	if (capacity == 2 && stacks -> a -> elements[0] > stacks -> a -> elements[1])
	{
		sa(stacks);
	}
	else if (capacity == 3)
	{
		sort_three(stacks);
	}
	else if (capacity >= 4 && capacity <= 5)
	{
		sort_four_five(stacks);
	}

	return (0);
}

void	sort_four_five(t_stacks *s)
{
	while (s -> b -> top <= 1)
	{
		if (s -> a -> elements [0] == 0 || s -> a -> elements[0] == 1)
			pb(s);
		else
			ra(s);
	}
	if (s -> b -> elements[0] == 0)
		sb(s);
	if (s -> a -> elements[2] != 4)
	{
		if (s -> a -> elements[0] == 4)
			ra(s);
		else
			rra(s);
	}
	if (s-> a -> elements[0] > s -> a -> elements[1])
		sa(s);
	pa(s);
	pa(s);
}

void	sort_three(t_stacks *s)
{
	if (s -> a -> elements[2] != 2)
	{
		if (s -> a -> elements[0] == 2)
			ra(s);
		else
			rra(s);
	}
	if (s -> a -> elements[0] > s -> a -> elements[1] )
		sa(s);
}
