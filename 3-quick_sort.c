#include "sort.h"

/**
 * swap - swaps elements
 * @n: points to first element
 * @m: points to second element
 * Return: no value
 */
void swap(int *n, int *m)
{
	int tmp = *n;

	*n = *m;
	*m = tmp;
}

/**
 * lomuto_partition - finds the partition position
 * @array: points to array
 * @low: index of first element
 * @high: index of last element
 * Return: 1
 */
int lomuto_partition(int *array, int low, int high)
{
	int point = array[high];
	int a = (low - 1), b;

	for (b = low; b < high; b++)
	{
		if (array[b] <= point)
		{
			a++;
			swap(&array[a], &array[b]);
		}
	}

	swap(&array[a + 1], &array[high]);

	return (a + 1);
}

/**
 * QuickSort - sort function
 * @array: points to array
 * @low: index of first element
 * @high: index of last element
 * Return: no value
 */
void QuickSort(int *array, int low, int high)
{
	if (low < high)
	{
		int point_idx = lomuto_partition(array, low, high);

		QuickSort(array, low, point_idx - 1);
		QuickSort(array, point_idx + 1, high);
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
	if (size < 2)
	{
		return;
	}

	QuickSort(array, 0, size - 1);
}
