#include "sort.h"

/**
 * swap - swaps two int
 * @a: int
 * @b: int
 * Return: (void) the swaped int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partitions an array and uses pviot
 * @array: Array
 * @low: int
 * @high: int
 * @size: the size of array (size_t)
 * Return: index of pivote (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_qsort - Sorting Recursively an array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: the highest value of the array
 * @size: Size of the array
 * Return: Void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - quick sort algorithm using lomuto partitin
 * @array: array to sort
 * @size: Size of the array
 * Return: sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
