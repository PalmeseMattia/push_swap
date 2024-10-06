/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:19:44 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/06 15:37:46 by dpalmese         ###   ########.fr       */
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

void	sort(t_stacks *s)
{
	int 	capacity;
	capacity = s -> a -> capacity;

	if (capacity == 2 && s -> a -> elements[0] > s -> a -> elements[1])
		sa(s);
	else if (capacity == 3)
		sort_three(s);
	else if (capacity >= 4 && capacity <= 5)
		sort_four_five(s);
	else
		radix_sort(s);
}

void	radix_sort(t_stacks *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s -> a -> top;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = 0;
	while (j <= bit_size)
	{
		size = s -> a -> top;
		while (size-- && !is_sorted(s -> a -> elements, s -> a -> top))
		{
			if (((s -> a -> elements[0] >> j) & 1) == 0)
				pb(s);
			else
				ra(s);
		}
		radix_sort_b(s, s -> b -> top, bit_size, j + 1);
		j++;
	}
	while (s -> b -> top != 0)
		pa(s);
}

void	radix_sort_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_sorted(s -> a -> elements, s -> a -> top))
	{
		if (((s -> b -> elements[0] >> j) & 1) == 0)
			rb(s);
		else
			pa(s);
	}
	if (is_sorted(s -> a -> elements, s -> a -> top))
		while (s -> b -> top != 0)
			pa(s);
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
