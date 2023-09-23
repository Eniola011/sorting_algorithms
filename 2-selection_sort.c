#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array
 * @size: size of array
 * Return: no value
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t a, b, min;

	for (a = 0; a < size; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[min] > array[b])
			{
				min = b;
			}
		}

		if (a != min)
		{
			temp = array[a];
			array[a] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
