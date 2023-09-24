#include "sort.h"

/**
 * swap - swaps elements
 * @n: points to first element
 * @m: points to second element
 * @array: an array
 * @size: size of the array
 * Return: no value
 */
void swap(int *array, size_t size, int *n, int *m)
{
	if (*n != *m)
	{
		*n = *n + *m;
		*m = *n - *m;
		*n = *n - *m;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - finds the partition position
 * @array: points to array
 * @size: size of array
 * @low: index of first element
 * @high: index of last element
 * Return: 1
 */
int lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int point = array[high];
	int a, b;

	for (a = b = low; b < high; b++)
	{
		if (array[b] < point)
		{
			swap(array, size, &array[b], &array[a++]);
		}
	}

	swap(array, size, &array[a], &array[high]);

	return (a);
}

/**
 * QuickSort - sort function
 * @array: points to array
 * @size: size of array
 * @low: index of first element
 * @high: index of last element
 * Return: no value
 */
void QuickSort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t point_idx = lomuto_partition(array, size, low, high);

		QuickSort(array, size, low, point_idx - 1);
		QuickSort(array, size, point_idx + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array
 * @size: size of the array
 * Return: no value
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}

	QuickSort(array, size, 0, size - 1);
}
