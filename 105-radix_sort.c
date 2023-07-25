#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sorts an arrray using radix sorrt algorith
 * @array: is the array of ints
 * @size: is the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, i, place, size1;

	size1 = size;
	max = array[0];

	if (size < 2 || !array)
		return;
	for (i = 0; i < size1; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (place = 1; (max / place) > 0; place *= 10)
	{
		count_sort(array, size1, place);
		print_array(array, size);
	}
}
/**
 * count_sort - sorts the array of ints using counts sort
 * @array: is the arrayof ints
 * @size: is the size of the array
 * @place: is the position of the digit
 *	if (431 - 1 is at first place: 3 - secont place 4 - third)
 */
void count_sort(int *array, int size, int place)
{
	int *output, *count_arr;
	int i, max;

	/* get the max in the place */
	max = (array[0] / place) % 10;
	for (i = 0; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	count_arr = malloc(sizeof(int) * (max + 1));
	if (!count_arr)
		return;

	for (i = 0; i < max; i++)
		count_arr[i] = 0;

	for (i = 0; i < size; i++)
		count_arr[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count_arr[i] += count_arr[i - 1];

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = size - 1; i >= 0; i--)
	{
		output[count_arr[((array[i] / place) % 10)] - 1] = array[i];
		count_arr[((array[i] / place) % 10)]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count_arr);
	free(output);
}
