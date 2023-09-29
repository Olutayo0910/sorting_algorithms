#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* Pivot is the last element */
	int i = low - 1; /* Index of smaller element */

	for (int j = low; j <= high - 1; j++)
	{
		/* If current element is smaller or equal to the pivot */
		if (array[j] <= pivot)
		{
			i++;
			/* Swap array[i] and array[j] */
			if (i != j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	/* Swap the pivot element with the element at index i+1 */
	if (i + 1 != high)
	{
		int temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return i + 1; /* Return the index of the pivot element */
}

/**
 * quick_sort_recursive - Recursively applies Quick Sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		/* Partition the array into two subarrays */
		int pi = lomuto_partition(array, low, high, size);

		/* Recursively sort the subarrays */
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
