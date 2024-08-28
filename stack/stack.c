#include "stack.h"

t_stack	*create_stack(unsigned int n)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack -> capacity = n;
	stack -> top = -1;
	if (n > 0)
	{
		stack -> elements = calloc(stack -> capacity, sizeof(int));
		if (stack -> elements == NULL)
		{
			free(stack);
			return (NULL);
		}
	}
	else
		stack -> elements = NULL;
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (stack -> top == -1);
}

int is_full(t_stack *stack)
{
	return (stack -> top == stack -> capacity -1);
}

void push(t_stack *stack, int n)
{
	if (!is_full(stack))
		stack -> elements[++(stack -> top)] = n;
}

void push_back(t_stack *stack, int n)
{
	int	i;

	if(!is_full(stack))
	{
		i = stack -> top;
		while(i >= 0)
		{
			stack -> elements[i + 1] = stack -> elements[i];
			i--;
		}
		stack -> elements[0] = n;
		stack -> top++;
	}
}

void pop(t_stack *stack) //TODO: fix logic, what if is empty? Garbage is returned :/ Maybe a void pop would be better
{
	if(!is_empty(stack))
	{
		stack -> top--;
	}
}

int peek(t_stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return (stack -> elements[stack ->top]);
}

void free_stack(t_stack *stack)
{
	if (stack -> elements != NULL)
		free(stack -> elements);
	if (stack)
		free(stack);
}

void print_stack(t_stack *stack)
{
	printf("[");
	for(int i = 0; i <= stack -> top; i++) {
		printf("%d", stack -> elements[i]);
		if(i != stack -> top)
			printf(", ");
	}
	printf("]\n");
}

