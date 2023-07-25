#ifndef SORT_H
#define SORT_H

#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* function of sorting algorthims */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic(int *array, int left, int size, int dir, int origin);
void bitonic_merge(int *array, int left, int size, int dir);
void bitonic_sort(int *array, size_t size);


/* support function */
void swap(int *item1, int *item2);
void count_sort(int *array, int size, int place);
void swap_nodes(listint_t *A, listint_t *B);
void refreshPointers(listint_t *A);

/* in quick sort */
void swap_quick(int *A, int *B);
int partition(int *array, int low, int high, size_t size);
void quick_s(int *array, int low, int high, size_t size);

/*in cocktail shaker sort */
void swap_nodes_cocktail(listint_t *A, listint_t *B);
void refreshPointers_sort(listint_t *A);
int backward_sort(listint_t **list, listint_t *temp);
int forward_sort(listint_t **list, listint_t *temp);

/* in merge sort */
void merge_sort_recursion(int *array, int left, int right);
void merge(int *array, int left, int middle, int right);

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
#endif
