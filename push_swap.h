#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "./stack/stack.h"

#define MAX_DEPTH 5

typedef void(*ops)(t_stacks *);
static ops operations[11] = {sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr};
static char *operations_name[11] = {"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"};
void quickSort(int *arr, int low, int high);
void dfs(t_stacks *stacks, int depth, int *sorted, t_stacks *best);

#endif
