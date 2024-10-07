/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:20:53 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/07 17:42:01 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	is_sorted(int *array, int size)
{
	if (size == 0 || size == 1)
		return (1);
	while (size > 0)
	{
		if (array[size - 1] < array[size - 2])
			return (0);
		size--;
	}
	return (1);
}

int	get_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	contains_duplicates(t_stacks *stacks)
{
	int		i;
	int		j;
	t_stack	*a;

	a = stacks -> a;
	i = 0;
	while (i < a -> top)
	{
		j = 0;
		while (j < a -> top)
		{
			if (j != i && a -> elements[i] == a -> elements[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_array(char **array)
{
	char	**copy;

	copy = array;
	if (copy)
	{
		while (*copy)
			free(*(copy++));
		free(array);
	}
}
