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
	int temp = 0, swap = 1;
	size_t a;

	if (!array || !size)
	{
		return;
	}

	while (swap)
	{
		swap = 0;
		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				temp = array[a + 1];
				array[a + 1] = array[a];
				array[a] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
