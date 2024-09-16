#include "push_swap.h"
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
void quickSort(int *arr, int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);  // pi is partitioning index
		quickSort(arr, low, pi - 1);  // recursively sort left subarray
		quickSort(arr, pi + 1, high);  // recursively sort right subarray
	}
}
