#include "./stack/stack.h"
#include <time.h>
#include <stdlib.h>

typedef void(*ops)(t_stacks *);

int main()
{
	// Initialize random
	srand(time(NULL));
	t_stacks *stacks = create_stacks(10);

	// Array of moves
	ops operations[11] = {sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr};
	// Push random elements in the stack
	for (int i = 0; i < 10; i++) {
		push(stacks -> a, rand() % 100);
	}

	// Array of possible permutations
	t_stacks **permutations = (t_stacks **)malloc(11 * sizeof(t_stacks *));
	for (int i = 0; i < 11; i++) {
		permutations[i] = create_stacks(10);
		copy_stacks(stacks, permutations[i]);
	}
	// Print and free the stack
	for (int i = 0; i < 11; i++) {
		print_stacks(permutations[i]);
	}
	free_stacks(stacks);
	return (0);
}
