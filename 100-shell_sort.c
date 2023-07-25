#include "sort.h"

/**
 * shell_sort - implements he shell sort algorithm using Knuth sequence
 * @array : array to be sorted
 * @size: the size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int temp;

	if (size < 2 || !array)
		return;

	while (interval <= size / 3)
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j > interval - 1&& array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j = j - interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
