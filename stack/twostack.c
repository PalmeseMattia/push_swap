#include "stack.h"

t_twostack	*create_twostack(int capacity)
{
	t_twostack	*result;

	result = (t_twostack *)malloc(sizeof(t_twostack));
	if (result == NULL)
		return (NULL);
	result -> a = create_stack(capacity);
	if (result -> a == NULL)
	{
		free(result);
		return (NULL);
	}
	result -> b = create_stack(capacity);
	if (result -> b == NULL)
	{
		free_stack(result -> a);
		free(result);
		return (NULL);
	}
	return (result);
}

void	free_twostack(t_twostack *twostack)
{
	if (twostack)
	{
		free_stack(twostack -> a);
		free_stack(twostack -> b);
		free(twostack);
	}
}
