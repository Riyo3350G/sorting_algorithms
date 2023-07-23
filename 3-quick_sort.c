#include "sort.h"

/**
 * swap - swaps two numbers
 * @a: The first number
 * @b: The second number
 **/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - split array around a pivot
 * @arr: The array
 * @first_elem: The first element
 * @last_elem: The last element
 * @size: Array size
 * Return: i integer
 */
int partition(int *arr, int first_elem, int last_elem, size_t size)
{
	int pivot = arr[last_elem];
	int i = first_elem;
	int j;

	for (j = first_elem; j < last_elem; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[last_elem]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * quickSort - sorts a part of the list
* @arr: The array to be sorted
 * @first_elem: first element
 * @last_elem: last element
 * @size: Array size
 * Return: no return
 */
void quickSort(int *arr, int first_elem, int last_elem, size_t size)
{
	int pivot;

	if (first_elem < last_elem)
	{
		pivot = partition(arr, first_elem, last_elem, size);
		quickSort(arr, first_elem, pivot - 1, size);
		quickSort(arr, pivot + 1, last_elem, size);
	}
}

/**
 * quick_sort - quick sort method of an array
 * @array: The array to be sorted
 * @size: The array size
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
