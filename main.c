#include "push_swap.h"
#include <time.h>
#include <stdlib.h>


/**
 * This functions takes two arrays as arguments
 * and returns the number of equal elements at the same index.
 * If we call this function with the sorted input we can get
 * the degree of orderliness of a stack
 */
int get_orderliness(int *sorted, int *target, int size)
{
	int result;

	result = 0;
	for(int i = 0; i < size; i++) {
		if (sorted[i] == target[i])
				result++;
	}
	return result;
}

int main()
{
	// Initialize random
	srand(time(NULL));
	t_stacks *stacks = create_stacks(10);
	
	// Push random elements in the stack
	for (int i = 0; i < 10; i++) {
		push(stacks -> a, rand() % 100);
	}
	printf("Original stack:\n");
	print_stacks(stacks);
	
	// Get the sorted Array
	int *sorted = (int *)calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++) {
		sorted[i] = stacks -> a -> elements[i];
	}
	quickSort(sorted, 0, 9);
	printf("Sorted array:\n[");
	for (int i = 0; i < 9; i++) {
		printf("%d ,",sorted[i]);
	}
	printf("%d]",sorted[9]);
	printf("\n\n");

	t_stacks *best = create_stacks(10);
	
	dfs(stacks, 0, sorted, best);
	
	printf("Best stack is:\n");
	print_stacks(best);
	
	free_stacks(stacks);
	free(sorted);
	return (0);
}

void dfs(t_stacks *stacks, int depth, int *sorted, t_stacks *best)
{
	//For each copy we do a DFS
	t_stacks **copies = (t_stacks **)malloc(11 * sizeof(t_stacks *));
	for (int i = 0; i < 11; i++) {
		//Create a copy of the original stack
		copies[i] = create_stacks(10);
		copy_stacks(stacks, copies[i]);
		//Apply operation
		operations[i](copies[i]);
		copies[i] -> orderliness = get_orderliness(sorted, copies[i] -> a -> elements, copies[i] -> a -> top);
		add_operation(copies[i], operations_name[i]);
		//Go deep on this copy if not at max depth
		if (depth < MAX_DEPTH)
				dfs(copies[i], depth + 1, sorted, best);
		//Store if the stack is the most sorted in less moves
		if (copies[i] -> orderliness >= best -> orderliness) {
			if (copies[i] -> orderliness == best -> orderliness) {
				if (copies[i] -> n_operations < best -> n_operations)
					copy_stacks(copies[i], best);
			} else {
				copy_stacks(copies[i], best);
			}
		}
		//print_stacks(copies[i]);
		free_stacks(copies[i]);
	}
	free(copies);
}
