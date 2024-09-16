#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "./stack/stack.h"

#define MAX_DEPTH 4
#define TABOO_BUFFER 100

typedef void(*ops)(t_stacks *);

typedef struct s_taboo
{
	t_stacks	**stacks;
	int			top;
	int			buffer;
}	t_taboo;

static ops operations[11] = {sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr};
static char *operations_name[11] = {"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"};

void	quickSort(int *arr, int low, int high);
void	dfs(t_stacks *stacks, int depth, int *sorted, t_stacks *best, t_taboo taboo);

// Taboo functions
t_taboo create_taboo();
void	add_taboo(t_stacks *stacks, t_taboo *taboo);
int		in_taboo(t_stacks *stacks, t_taboo taboo);
void	free_taboo(t_taboo taboo);
void	print_taboo(t_taboo taboo);

#endif
