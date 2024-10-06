/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:41:39 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/06 15:48:52 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort(t_stacks *s)
{
	int	capacity;

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
	int	*a;
	int	*b;

	a = s -> a -> elements;
	b = s -> b -> elements;
	while (b_size-- && j <= bit_size && !is_sorted(a, s -> a -> top))
	{
		if (((b[0] >> j) & 1) == 0)
			rb(s);
		else
			pa(s);
	}
	if (is_sorted(a, s -> a -> top))
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
	if (s -> a -> elements[0] > s -> a -> elements[1])
		sa(s);
}
