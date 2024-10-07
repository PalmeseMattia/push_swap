/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:16:43 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/07 17:30:46 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_strisnum(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}
