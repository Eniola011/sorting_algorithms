#include "sort.h"

/**
 * get_max_gap - gets biggest Knuth Sequence space for size
 * @size: size of array
 * Return: size of space
 */
size_t biggest_space(size_t size)
{
	size_t n = 1;

	while (n < size)
	{
		n = n * 3 + 1;
	}

	return ((n - 1) / 3);
}

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
	size_t n, a, b;
	int temp;

	if (!array || !size)
	{
		return;
	}

	for (n = biggest_space(size); n; n = (n - 1) / 3)
	{
		for (a = n; a < size; a++)
		{
			temp = array[a];
			for (b = a; b > n - 1 && array[b - n] > temp; b -= n)
			{
				array[b] = array[b - n];
			}
			array[b] = temp;
		}
		print_array(array, size);
	}
}
