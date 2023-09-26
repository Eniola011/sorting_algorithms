#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * Knuth's increments: 1, 4, 13, …, (3k – 1) / 2
 * n+1 = n * 3 + 1
 * @array: array
 * @size: size of array
 * Return: no value
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t n = 1;
	size_t i;
	size_t idx;

	while (n <= size / 3)
	{
		n = n * 3 + 1;
	}

	while (n > 0)
	{
		print_array(array, size);

		for (idx = n; idx < size; idx++)
		{
			temp = array[idx];
			i = idx;
			while (i >= n && array[i - n] > temp)
			{
				array[i] = array[i - n];
				i -= n;
			}

			array[i] = temp;
		}

		n = (n - 1) / 3;
	}

	print_array(array, size);
}
