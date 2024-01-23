#include "sort.h"

/**
 * swap_nodes - function swaps two nodes in a listint_t doubly-linked list.
 * @h: (double pointer) to the head of the doubly-linked list.
 * @n1: (double pointer) to the first node to swap.
 * @n2: (pointer)second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function sorts a doubly linked list of ints
 *                       using the insertion sort algorithm.
 * @list: (double pointer) to the head of a doubly-linked list of integers.
 * Description: function prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itervarble, *insertvarble, *tmpvarble;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itervarble = (*list)->next; itervarble != NULL; itervarble = tmpvarble)
	{
		tmpvarble = itervarble->next;
		insertvarble = itervarble->prev;
		while (insertvarble != NULL && itervarble->n < insertvarble->n)
		{
			swap_nodes(list, &insertvarble, itervarble);
			print_list((const listint_t *)*list);
		}
	}
}
