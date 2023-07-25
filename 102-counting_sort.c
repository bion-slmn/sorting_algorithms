#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts that array using count sort
 * @array: an array to be sorted
 * @size: is the sise of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t max, i;
	int *count_arr, *output, max1;

	if (!array || size < 2)
		return;

	/* find the max value in the aray*/
	max1 = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max1)
			max1 = array[i];
	}
	max = max1;

	count_arr = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * (size));
	if (!count_arr || !output)
		return;

	for (i = 0; i <= max; i++)
		count_arr[i] = 0;
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	for (i = 1; i <= max; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max + 1);
	for (i = 0; i < size; i++)
	{
		output[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count_arr);
}
