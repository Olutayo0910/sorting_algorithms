#include "sort.h"

/**
 * inter - sort an array of int in ascending order
 * @array: array to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */
void inter(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] == array[j])
		return;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}
/**
 * partition - sort array partition
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int split_idx = start;
	int j;

	for (j = start; j < end; j++)
		if (array[j] < pivot)
			inter(array, split_idx++, j, size);
	inter(array, split_idx, end, size);
	return (split_idx);
}
/**
 * sort_recursive - quick_sort recursive
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void sort_recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = partition(array, start, end, size);

		sort_recursive(array, start, pivot_pos - 1, size);
		sort_recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	sort_recursive(array, 0, size - 1, size);
}
