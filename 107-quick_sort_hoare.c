#include "sort.h"

/**
 * quick_sort_hoare - sorts the array using hoare quick method
 * @array: to be sorted
 * @size: is the size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int size1 = size;

	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size1);
}

/**
 * quicksort_hoare - sorted the array using hoare method
 * @array: to be sorted
 * @size: is the size of array
 * @left: leftmost index
 * @right: right most index
 *
 * Return: nothing
 */
void quicksort_hoare(int array[], int left, int right, int size)
{
	int p;

	if (left < right)
	{
		p = partition_hoare(array, left, right, size);
		quicksort_hoare(array, left, p - 1, size);
		quicksort_hoare(array, p, right, size);
	}
}
/**
 * partition_hoare - divides the array using hoare method
 * @array: to be sorted
 * @size: is the size of array
 * @left: leftmost index
 * @right: right most index
 *
 * Return: the index of the right most pointer
 */
int partition_hoare(int array[], int left, int right, int size)
{
	int i = left - 1;
	int j = right + 1;
	int pivot = array[right];
	int temp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
