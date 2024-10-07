/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:19:44 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/07 13:29:07 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(int *array, int size)
{
	while (size > 0)
	{
		if (array[size - 1] < array[size - 2])
			return (0);
		size--;
	}
	return (1);
}

void	check_input(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strisnum(args[i]))
		{
			ft_printf("Error: Please provide strictly numerical values\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	rank_elements(t_stacks *stacks)
{
	int	i;
	int	j;
	int	*new_elements;

	i = 0;
	new_elements = (int *)calloc(stacks -> a -> capacity, sizeof(int));
	while (i < stacks -> a -> capacity)
	{
		j = 0;
		while (j < stacks -> a -> capacity)
		{
			if (stacks -> a -> elements[i] > stacks -> a -> elements[j])
				new_elements[i]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stacks -> a -> capacity)
	{
		stacks -> a -> elements[i] = new_elements[i];
		i++;
	}
	free(new_elements);
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		i++;
	return (i);
}

void	push_elements(t_stacks *stacks, char **elements)
{
	int	i;

	i = 0;
	while (i < stacks -> a -> capacity)
	{
		push(stacks, ft_atoi(elements[i]));
		i++;
	}
}

t_stacks	*parse_args(int argc, char **argv)
{
	char		**args;
	t_stacks	*stacks;

	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		check_input(args, get_array_size(args));
		stacks = new_stacks(get_array_size(args));
		push_elements(stacks, args);
	}
	else
	{
		check_input(argv + 1, argc - 1);
		stacks = new_stacks(argc - 1);
		push_elements(stacks, argv + 1);
	}
	if (args)
		free(args);
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
	{
		exit(EXIT_SUCCESS);
	}
	stacks = parse_args(argc, argv);
	rank_elements(stacks);
	sort(stacks);
	free_stacks(stacks);
	return (0);
}
