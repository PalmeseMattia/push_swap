#include "./stack/stack.h"
#include <time.h>
#include <stdlib.h>

typedef void(*ops)(t_stacks *);

// Function to swap two elements
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function: selects a pivot and partitions the array around it
int partition(int *arr, int low, int high) {
	int pivot = arr[high];  // pivot element
	int i = (low - 1);  // index of smaller element

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;  // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// QuickSort function
void quickSort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // pi is partitioning index
		quickSort(arr, low, pi - 1);  // recursively sort left subarray
		quickSort(arr, pi + 1, high);  // recursively sort right subarray
	}
}
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
	// Array of moves
	ops operations[11] = {sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr};
	char *operations_name[] = {"sa","sb","ss","pa","pb","ra","rb","rr","rra","rrb","rrr"};
	
	// Push random elements in the stack
	for (int i = 0; i < 10; i++) {
		push(stacks -> a, rand() % 100);
	}
	
	// Get the sorted Array
	int *sorted = (int *)calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++) {
		sorted[i] = stacks -> a -> elements[i];
	}
	quickSort(sorted, 0, 9);
	printf("Sorted array:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ,",sorted[i]);
	}
	printf("\n\n");

	// Array of possible permutations
	t_stacks **permutations = (t_stacks **)malloc(11 * sizeof(t_stacks *));
	for (int i = 0; i < 11; i++) {
		permutations[i] = create_stacks(10);
		copy_stacks(stacks, permutations[i]);
	}
	// Print and free the stack
	for (int i = 0; i < 11; i++) {
		operations[i](permutations[i]);
		permutations[i] -> orderliness = get_orderliness(sorted, permutations[i] -> a -> elements, 10);
		add_operation(permutations[i], operations_name[i]);
		print_stacks(permutations[i]);
		printf("\n");
	}
	free_stacks(stacks);
	return (0);
}


