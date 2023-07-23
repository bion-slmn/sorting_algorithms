#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - the insert sort algorthim sorts in ascending order.
 * @list : is a doubly linked list of integers
 *
 * Return : none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	/* loop till the end of the list */
	temp = temp->next;
	while (temp != NULL)
	{
		/* compare and swap items in the list on the left side */
		while (temp->n < temp->prev->n)
		{
			swap_nodes(temp->prev, temp);

/* swapping moves the node to the left no need of moving the piointer */

			if (temp->prev == NULL)
			{
				*list = temp;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		temp = temp->next;
	}
}

/**
 * swap_nodes - swaps two nodes
 * @A: is the node on the right side
 * @B: is the node on the left side
 */
void swap_nodes(listint_t *A, listint_t *B)
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

	refreshPointers(A);
	refreshPointers(B);
}

/**
 * refreshPointers - it makes sure that the outer pointers
 *			are upto date after swap
 * @A : is th node to up date its pointers
 */
void refreshPointers(listint_t *A)
{
	if (A->prev)
		A->prev->next = A;
	if (A->next)
		A->next->prev = A;
}
