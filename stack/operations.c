#include "stack.h"

/*
 * sa (swap a): Swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements.
 */
void	sa(t_twostack *twostack)
{
	int		tmp;
	t_stack	*a;

	a = twostack -> a;
	if (a && a -> top > 1)
	{
		tmp = seek(a);
		a -> elements[a -> top] = a -> elements[a -> top -1];
		a -> elements[a -> top - 1] = tmp;
	}
}

/*
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements.
 */
void	sb(t_twostack *twostack)
{
	int		tmp;
	t_stack	*b;

	b = twostack -> b;
	if (b && b -> top > 1)
	{
		tmp = seek(b);
		b -> elements[b -> top] = b -> elements[b -> top -1];
		b -> elements[b -> top - 1] = tmp;
	}
}

/*
 * ss : sa and sb at the same time.
 */
void	ss(t_twostack *twostack)
{
	sa(twostack);
	sb(twostack);
}

/*
 * pa (push a): Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 */
void	pa(t_twostack *twostack)
{
	int		tmp;
	t_stack	*a;
	t_stack	*b;

	a = twostack -> a;
	b = twostack -> b;
	if (!is_empty(b) && !is_full(a))
		push(a, pop(b));
}

/*
 * pb (push b): Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 */
void	pb(t_twostack *twostack)
{
	int		tmp;
	t_stack	*a;
	t_stack	*b;

	a = twostack -> a;
	b = twostack -> b;
	if (!is_empty(a) && !is_full(b))
		push(b, pop(a));
}

/*
 * ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_twostack *twostack)
{
	t_stack	*a;

	a = twostack -> a;
	if (!is_empty(a))
		push_back(a, pop(a));
}

/*
 * rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */

/*
 * rr : ra and rb at the same time.
 */

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



