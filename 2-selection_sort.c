#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sort the arrar using selection sort algorithm
 * @array: array to be sorted
 * @size: is the size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, small;
	/* first loop to pass over every element */
	for (i = 0; i <= size - 1; i++)
	{
		small = i;
		/* second loop to find the smallest in the elememts */
		for (j = i; j <= size - 1; j++)
		{
			if (array[j] < array[small])
			{
				small = j;
			}
		}

		/* swap th smallest with the one in the first loop */
		if (small != i)
		{
			temp = array[small];
			array[small] = array[i];
			array[i] = temp;

	/* print the array after every swap */
			print_array(array, size);
		}
	}
}
