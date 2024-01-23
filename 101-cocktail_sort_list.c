#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - function swaps a node in a listint_t doubly-linked list
 *                   list of ints with the node ahead of it.
 * @list: (double pointer) to the head of a doubly-linked list of integers.
 * @tail: (double pointer) to the tail of the doubly-linked list.
 * @shaker: (double pointer) to the current swapping node of the 
 * cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpvrble = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpvrble;
	else
		*list = tmpvrble;
	tmpvrble->prev = (*shaker)->prev;
	(*shaker)->next = tmpvrble->next;
	if (tmpvrble->next != NULL)
		tmpvrble->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpvrble;
	tmpvrble->next = *shaker;
	*shaker = tmpvrble;
}

/**
 * swap_node_behind - (function)swap a node in a listint_t doubly-linked
 *                    list of ints with the node behind it.
 * @list: (double pointer) to the head of a doubly-linked list of integers.
 * @tail: (double pointer) to the tail of the doubly-linked list.
 * @shaker: (double pointer) to the current swapping node of the
 * cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpvrble = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpvrble;
	else
		*tail = tmpvrble;
	tmpvrble->next = (*shaker)->next;
	(*shaker)->prev = tmpvrble->prev;
	if (tmpvrble->prev != NULL)
		tmpvrble->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpvrble;
	tmpvrble->prev = *shaker;
	*shaker = tmpvrble;
}

/**
 * cocktail_sort_list - function sorts a listint_t doubly-linked list of ints in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: (double pointer) to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tailvrble, *shakervrble;
	bool shaken_not_stirredvrble = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tailvrble = *list; tailvrble->next != NULL;)
		tailvrble = tailvrble->next;

	while (shaken_not_stirredvrble == false)
	{
		shaken_not_stirredvrble = true;
		for (shakervrble = *list; shakervrble != tailvrble; shakervrble = shakervrble->next)
		{
			if (shakervrble->n > shakervrble->next->n)
			{
				swap_node_ahead(list, &tailvrble, &shakervrble);
				print_list((const listint_t *)*list);
				shaken_not_stirredvrble = false;
			}
		}
		for (shakervrble = shakervrble->prev; shakervrble != *list;
				shakervrble = shakervrble->prev)
		{
			if (shakervrble->n < shakervrble->prev->n)
			{
				swap_node_behind(list, &tailvrble, &shakervrble);
				print_list((const listint_t *)*list);
				shaken_not_stirredvrble = false;
			}
		}
	}
}
