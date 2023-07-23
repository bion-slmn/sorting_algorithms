#include "sort.h"

/**
* swap - it swaps two items
* @item1 : is the first element to be swapped
* @item2 : is the second element tobe swapped
*/
void swap(int *item1, int *item2)
{
	int temp;

	temp = item1;
	item1 = item2;
	item2 = temp;
}
