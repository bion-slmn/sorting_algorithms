#include "sort.h"

/**
 * cocktail_sort_list - sorts a double listing using cocktail_sort
 *			algorithm
 * @list: the head of the double listing
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		while (temp->next)
		{
			if (temp->n > temp->next->n)
				swapped = forward_sort(list, temp);
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
				swapped = backward_sort(list, temp);
			else
				temp = temp->prev;
		}
	}
}
/**
 * backward_sort - swaps the nodes in the backward sorting direction
 * @list: the head of the node;
 * @temp: is the pointer to be swapped
 *
 * Return: 1
 */

int backward_sort(listint_t **list, listint_t *temp)
{
	swap_nodes_cocktail(temp->prev, temp);
	if (temp->prev == NULL)
	{
		*list = temp;
		print_list(*list);
	}
	else
	{
		print_list(*list);
	}
	return (1);
}

/**
 * forward_sort - swaps the nodes in the forward sorting
 * @list: the head of the node;
 * @temp: is the pointer to be swapped
 *
 * Return: 1
 */
int forward_sort(listint_t **list, listint_t *temp)
{
	swap_nodes_cocktail(temp, temp->next);
	if (temp->prev->prev == NULL)
	{
		*list = temp->prev;
		print_list(*list);
	}
	else
		print_list(*list);

	return (1);
}

/**
 * swap_nodes_cocktail - swaps two nodes
 * @A: is the node on the right side
 * @B: is the node on the left side
 */
void swap_nodes_cocktail(listint_t *A, listint_t *B)
{

	listint_t *pointers[4];

	pointers[0] = A->next;
	pointers[1] = A->prev;
	pointers[2] = B->next;
	pointers[3] = B->prev;

	A->next = pointers[2];
	A->prev = pointers[0];
	B->prev = pointers[1];
	B->next = pointers[3];

	refreshPointers_sort(A);
	refreshPointers_sort(B);
}

/**
 * refreshPointers_sort - it makes sure that the outer pointers
 *                      are upto date after swap
 * @A : is th node to up date its pointers
 */
void refreshPointers_sort(listint_t *A)
{
	if (A->prev)
		A->prev->next = A;
	if (A->next)
		A->next->prev = A;
}
