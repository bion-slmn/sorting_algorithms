#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * merge_sort - sorts an array using merge sort algorithm
 * @array: is the arrray to be sorted
 * @size: is the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int left_index = 0;
	int right_index = size - 1;

	if (!array || size < 2)
		return;

	merge_sort_recursion(array, left_index, right_index);

}

/**
 * merge_sort_recursion - its main program that divides the array nd sorts
 *			using merge sort method
 * @left: is the left most index of array
 * @right: is the right most index of array
 * @array: the array to be sorted
 */
void merge_sort_recursion(int *array, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (right + left - 1) / 2;
		merge_sort_recursion(array, left, middle);
		merge_sort_recursion(array, middle + 1, right);
		printf("Merging...\n");
		merge(array, left, middle, right);
	}
}

/**
 * merge - merges the sub arrays and sorts them int right order
 * @array: is the array to be sorted
 * @left: is the left most index of the subarray
 * @right: is the right most indexs of the sub array
 * @middle: is the middle section of th sub array
 */
void merge(int *array, int left, int middle, int right)
{
	int r, i = 0, j = 0, k = left, n1 = middle - left + 1;
	int n2 = right - middle;
	int *dup = malloc(sizeof(int) * (n1 + n2));

	if (!dup)
		return;
	for (r = 0; r < n1 + n2; r++)
		dup[r] = array[left + r];
	printf("[left]:");
	print_array(dup, n1);
	printf("[right]:");
	print_array(&dup[n1], n2);
	while (i < n1 && j < n2)
	{
		if (dup[i] <= dup[j + n1])
		{
			array[k] = dup[i];
			i++;
		}
		else
		{
			array[k] = dup[j + n1];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = dup[i];
		i++;
		k++;
	}
	for (; j < n2; k++, j++)
		array[k] = dup[n1 + j];
	free(dup);
	printf("[Done]:");
	print_array(array + left, right - left + 1);
}
