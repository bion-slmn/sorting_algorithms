#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - sorts an array using quick sort alogrithm
 * @array: is the array to be sorted
 * @size: is the size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * quick_s - sorts an array using quick sort alogrithm
 * @array: is the array to be sorted
 * @size: is the size of array
 * @low: is the left most index of the sub array/ array
 * @high: is the right most index of the subarray/array
 */
void quick_s(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quick_s(array, low, p - 1, size);
		quick_s(array, p + 1, high, size);
	}
}

/**
 * partition - it sorts the array so that the items on the left
 *		are smaller than the pivot and those on the right are larger
 * @array: the array to be sorted
 * @size: is the size of the array
 * @low: is the left most of the array
 * @high: is the right most index
 *
 * Return: the index of the pivot element after sorting
 */
int partition(int array[], int low, int high, size_t size)
{
	int j, pivot, i = low - 1;

	pivot = high;

	for (j = low; j < high; j++)
	{
		if (array[j] < array[pivot])
		{
			i++;
			if (array[j] != array[i])
			{
				swap_quick(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[pivot])
	{
		swap_quick(&array[i + 1], &array[pivot]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap_quick - swap two values in the quick sort
 * @A: first pointer on the left side
 * @B: second pointer on the right side
 */
void swap_quick(int *A, int *B)
{
	int temp;

	temp = *A;
	*A = *B;
	*B = temp;
}
