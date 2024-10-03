/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:28:04 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/03 22:28:07 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

void	push(t_stacks *s, int num)
{
	if (s -> a -> top < s -> a -> capacity)
	{
		s -> a -> elements[s -> a -> top++] = num;
	}
}
