#include "sort.h"

void merge_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		  size_t back);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: subarray of an array of int to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index.
 * @mid: The middle index.
 * @back: The back index.
 */
void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		  size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(subarr + front, mid - front);

printf("[right]: ");
print_array(subarr + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
for (; i < mid; i++)
buff[k++] = subarr[i];
for (; j < back; j++)
buff[k++] = subarr[j];
for (i = front, k = 0; i < back; i++)
subarr[i] = buff[k++];

printf("[Done]: ");
print_array(subarr + front, back - front);
}

/**
 * merge_recursive - Implement the merge sort algorithm
 * @subarr: subarray of an array of integers to sort.
 * @buff: A buffer to store the result.
 * @front: The front index
 * @back: The back index
 */
void merge_recursive(int *subarr, int *buff, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_recursive(subarr, buff, front, mid);
merge_recursive(subarr, buff, mid, back);
merge_subarray(subarr, buff, front, mid, back);
}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
int *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

merge_recursive(array, buff, 0, size);

free(buff);
}
