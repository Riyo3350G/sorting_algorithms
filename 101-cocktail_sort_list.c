#include "sort.h"

/**
 * swaper - Swaps two nodes
 * @node1: The first node
 * @node2: The last  node
 * @head: The head of list
 *
 * Return: No return
 */

void swaper(listint_t *node1, listint_t *node2, listint_t **head)
{
	listint_t *tmp;

	tmp = node1->prev;
	if (tmp)
		tmp->next = node2;
	node2->prev = tmp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*head = node2;
	print_list(*head);
}

/**
 * cocktail_sort_list -  sorts a doubly linked list of integers in
 *		ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int is_sorted = 1;
	int start = 0, end = 0;
	int current_index;

	if (list == NULL)
		return;
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next, end++;
	tmp = *list;
	while (is_sorted == 1)
	{
		current_index = start;
		while (current_index < end)
		{
			if (tmp->n > tmp->next->n)
			{
				swaper(tmp, tmp->next, list);
				is_sorted = 1;
			}
			else
				tmp = tmp->next;
			current_index++;
		}
		current_index = end;
		is_sorted = 0;
		while (current_index > start)
		{
			if (tmp->n < tmp->prev->n)
			{
				swaper(tmp->prev, tmp, list);
				is_sorted = 1;
			}
			else
				tmp = tmp->prev;
			current_index--;
		}
		start++;
	}
}
