#include "push_swap.h"

t_taboo create_taboo()
{
	t_taboo taboo;

	taboo.stacks =  (t_stacks **)malloc(TABOO_BUFFER * sizeof(t_stacks *));;
	taboo.top = 0;
	taboo.buffer = TABOO_BUFFER;
	return (taboo);
}

void	add_taboo(t_stacks *stacks, t_taboo *taboo)
{
	int	index;

	index = taboo -> top % taboo -> buffer;
	taboo -> stacks[index] = create_stacks(stacks -> a -> capacity);
	copy_stacks(stacks, taboo -> stacks[index]);
	taboo -> top++;
}

int	in_taboo(t_stacks *stacks, t_taboo taboo)
{
	for (int i = 0; i < taboo.top % taboo.buffer; i++) {
		if (equal(stacks, taboo.stacks[i]))
			return 1;
	}
	return 0;
}

void	print_taboo(t_taboo taboo)
{
	printf("\e[43mTaboo: \n");
	for (int i = 0; i < taboo.top % taboo.buffer; i++) {
		print_stacks(taboo.stacks[i]);
	}
	printf("\e[0m\n");
}

void free_taboo(t_taboo taboo)
{
	for (int i = 0; i < taboo.top % taboo.buffer; i++) {
		free_stacks(taboo.stacks[i]);
	}
	free(taboo.stacks);
}
