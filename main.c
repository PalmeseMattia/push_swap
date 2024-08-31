#include "./stack/stack.h"
#include <time.h>
#include <stdlib.h>

int main()
{
	// Initialize random
	srand(time(NULL));
	t_stacks *stacks = create_stacks(10);

	// Push random elements in the stack
	for (int i = 0; i < 10; i++) {
		push(stacks -> a, rand() % 100);
	}

	// Print and free the stack
	print_stacks(stacks);
	free_stacks(stacks);
	return (0);
}
