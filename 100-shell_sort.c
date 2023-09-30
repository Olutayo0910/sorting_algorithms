#include "sort.h"

/**
 * shell_sort -Sort an array using shell sort
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int space = 1;
	unsigned int i, j;
	int aux;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			aux = array[i];
			j = i;
			while (j >= space && array[j - space] > aux)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = aux;
		}
		print_array(array, size);
		space /= 3;
	}
}
