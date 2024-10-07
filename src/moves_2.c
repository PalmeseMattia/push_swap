/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:23:52 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/07 17:31:05 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	rb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	tmp = stacks -> b -> elements[0];
	i = 0;
	while (i < stacks -> b -> top - 1)
	{
		stacks -> b -> elements[i] = stacks -> b -> elements[i + 1];
		i++;
	}
	stacks -> b -> elements[i] = tmp;
	write(1, "rb\n", 3);
}

void	pa(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s -> b -> top == 0 || s -> a -> top == s -> a -> capacity)
		return ;
	tmp = s -> b -> elements[0];
	i = 0;
	while (i < s -> b -> top - 1)
	{
		s -> b -> elements[i] = s -> b -> elements[i + 1];
		i++;
	}
	s -> b -> top--;
	i = (++s -> a -> top) - 1;
	while (i > 0)
	{
		s -> a -> elements[i] = s -> a -> elements[i - 1];
		i--;
	}
	s -> a -> elements[0] = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s -> a -> top == 0 || s -> b -> top == s -> b -> capacity)
		return ;
	tmp = s -> a -> elements[0];
	i = 0;
	while (i < s -> a -> top - 1)
	{
		s -> a -> elements[i] = s -> a -> elements[i + 1];
		i++;
	}
	s -> a -> top--;
	i = (++s -> b -> top) - 1;
	while (i > 0)
	{
		s -> b -> elements[i] = s -> b -> elements[i - 1];
		i--;
	}
	s -> b -> elements[0] = tmp;
	write(1, "pb\n", 3);
}
