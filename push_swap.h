/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <dpalmese@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:16:08 by dpalmese          #+#    #+#             */
/*   Updated: 2024/10/06 15:34:40 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

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

int			ft_strisnum(char *str);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
t_stacks	*new_stacks(int capacity);
void		rank_elements(t_stacks *stacks);
void		push(t_stacks *s, int num);
void		sort_four_five(t_stacks *s);
void		radix_sort(t_stacks *s);
void		radix_sort_b(t_stacks *s, int b_size, int bit_size, int j);
void		sort_three(t_stacks *s);
void		sort(t_stacks *s);
#endif
