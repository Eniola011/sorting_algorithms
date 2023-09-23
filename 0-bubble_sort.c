#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array
 * @size: size of the array
 * Return: no value
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swap;
	size_t a, b;

	for (a = 0; a < size - 1; a++)
	{
		swap = 0;
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}

		if (swap == 0)
		{
			break;
		}
	}
}
