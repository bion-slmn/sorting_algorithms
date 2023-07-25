#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - sorts the array using bitonic sort algorith
 * @array: the array of it s to be sorted
 * @size: is the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int size1 = size;
	int dir = 1;

	if (size < 2 || !array)
		return;

	bitonic(array, 0, size1, dir, size1);
}
/**
 * bitonic - creates bitonic sequence
 * @array: is the array of ints to be sorted
 * @left: is the left most index of the array
 * @size: is the size of the sub array
 * @dir: is the direction of the sort (1 is ascending, 0 descending)
 * @origin: is the original size of the array
 */
void bitonic(int *array, int left, int size, int dir, int origin)
{
	int mid;

	if (size > 1)
	{
		mid = size / 2;

		printf("Merging [%d/%d] (%s):\n", size,
				origin, (dir == 1 ? "UP" : "DOWN"));
		print_array(array + left, size);

		bitonic(array, left, mid, 1, origin);
		bitonic(array, left + mid, mid, 0, origin);

		bitonic_merge(array, left, size, dir);

		printf("Result [%d/%d] (%s):\n", size,
				origin, (dir == 1 ? "UP" : "DOWN"));
		print_array(array + left, size);
	}
}
/**
 * bitonic_merge - merges the bitonic sequence
 * @array: is the array of ints to be sorted
 * @left: is the left most index of the array
 * @size: is the size of the sub array
 * @dir: is the direction of the sort (1 is ascending, 0 descending)
 */
void bitonic_merge(int *array, int left, int size, int dir)
{
	int mid;
	int i, temp;

	if (size > 1)
	{
		mid = size / 2;
		for (i = left; i < left + mid; i++)
		{
			if (dir == (array[i] > array[mid + i]))
			{
				temp = array[i];
				array[i] = array[mid + i];
				array[mid + i] = temp;

			}
		}

		bitonic_merge(array, left, mid, dir);
		bitonic_merge(array, left + mid, mid, dir);

	}
}
