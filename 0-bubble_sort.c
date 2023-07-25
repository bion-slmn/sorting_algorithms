#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - it sorts a list of int using the bubble sort algorithm
 * @array: is the arrray to be sorted
 * @size: is the size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapped, temp;

	if (size < 2 || !array)
		return;

	/* first loop for the number of passes */
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		/* the second loop for swapping and bubbling */
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1;

				/*after every swap print the array */
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}

}
