#include "stack.h"

/*
 * sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
void	sa(t_stacks *stacks)
{
	int		tmp;
	t_stack	*a;

	a = stacks -> a;
	if (a && a -> top >= 1)
	{
		tmp = peek(a);
		a -> elements[a -> top] = a -> elements[a -> top -1];
		a -> elements[a -> top - 1] = tmp;
	}
}

/*
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
void	sb(t_stacks *stacks)
{
	int		tmp;
	t_stack	*b;

	b = stacks -> b;
	if (b && b -> top >= 1)
	{
		tmp = peek(b);
		b -> elements[b -> top] = b -> elements[b -> top -1];
		b -> elements[b -> top - 1] = tmp;
	}
}

/*
 * ss : sa and sb at the same time.
 */
void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

/*
 * pa (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
void	pa(t_stacks *stacks)
{
	int		tmp;
	t_stack	*a;
	t_stack	*b;

	a = stacks -> a;
	b = stacks -> b;
	tmp = peek(b);
	if (!is_empty(b) && !is_full(a))
	{
		push(a, tmp);
		pop(b);
	}
}

/*
 * pb (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
void	pb(t_stacks *stacks)
{
	int		tmp;
	t_stack	*a;
	t_stack	*b;

	a = stacks -> a;
	b = stacks -> b;
	tmp = peek(a);
	if (!is_empty(a) && !is_full(b))
	{
		push(b, tmp);
		pop(a);
	}
}

/*
 * ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stacks *stacks)
{
	t_stack	*a;
	int		tmp;

	a = stacks -> a;
	tmp = peek(a);
	if (!is_empty(a))
	{
		pop(a);
		push_back(a, tmp);
	}
}

/*
 * rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stacks *stacks)
{
	t_stack	*b;
	int		tmp;

	b = stacks -> b;
	tmp = peek(b);
	if (!is_empty(b))
	{
		push_back(b, tmp);
		pop(b);
	}
}

/*
 * rr : ra and rb at the same time.
 */
void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

/*
 * rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */

/*
 * rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 */

/*
 *rrr : rra and rrb at the same time.
 */



