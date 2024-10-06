/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:19:44 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/06 15:42:26 by dpalmese         ###   ########.fr       */
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

void	check_input(int argc, char **argv)
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
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	if (argc < 2)
	{
		exit(EXIT_SUCCESS);
	}
	check_input(argc, argv);
	stacks = new_stacks(argc - 1);
	i = 1;
	while (i < argc)
	{
		push(stacks, ft_atoi(argv[i]));
		i++;
	}
	rank_elements(stacks);
	sort(stacks);
	return (0);
}
