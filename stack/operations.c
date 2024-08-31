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
void	rra(t_stacks *stacks)
{
		int		last;
		t_stack *a;
		int		i;

		a = stacks -> a;
		if (a -> top > 0)
		{
			last = a -> elements[0];
			i = 0;
			while (i < a -> top)
			{
				a -> elements[i] = a -> elements[i + 1];
				i++;
			}
			a -> elements[a -> top] = last;
		}
}

/*
 * rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 */
void	rrb(t_stacks *stacks)
{
		int		last;
		t_stack *b;
		int		i;

		b = stacks -> b;
		if (b -> top > 0)
		{
			last = b -> elements[0];
			i = 0;
			while (i < b -> top)
			{
				b -> elements[i] = b -> elements[i + 1];
				i++;
			}
			b -> elements[b -> top] = last;
		}
}
/*
 *rrr : rra and rrb at the same time.
 */
void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
