#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

/* quick sort */
void swap(int *a, int *b);
int partition(int *arr, int first_elem, int last_elem, size_t size);
void quickSort(int *arr, int first_elem, int last_elem, size_t size);
void quick_sort(int *array, size_t size);

/* counting_sort */
int max_val(int *array, int size);
void counting_sort(int *array, size_t size);

/* cocktail sort */
void swaper(listint_t *node1, listint_t *node2, listint_t **head);
void cocktail_sort_list(listint_t **list);

#endif
