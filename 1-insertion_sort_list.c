#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: list that will be sorted
 * Return: Nothing
*/
void insertion_sort_list(listint_t **list)
{
	/* initialize Nodes */
	listint_t *node = NULL;
	listint_t *helper = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	node = *list;
	node = node->next;

	while (node != NULL)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			/* swap nodes */
			helper = node;

			if (node->next)
				(node->next)->prev = helper->prev;

			(node->prev)->next = helper->next;
			node = node->prev;
			helper->prev = node->prev;
			helper->next = node;

			if (node->prev)
				(node->prev)->next = helper;

			node->prev = helper;

			if (helper->prev == NULL)
				*list = helper;

			print_list(*list);
			node = node->prev;
		}
		/* insert node */
		node = node->next;
	}
}
