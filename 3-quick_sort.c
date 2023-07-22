#include "sort.h"

/**
 * swap - function that swap two elements
 * @n1: first element
 * @n2: second element
 * Return: Nothing
*/
void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * quick_sort - function that sorts an array of integers
 * @array: array
 * @size: the size of array
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	srand(time(NULL));
	quick_sort_recursion(array, 0, size - 1);
}

/**
 * quick_sort_recursion - function that apply quick_sort
 * @array: array
 * @low_index: low index value in the array
 * @high_index: high index value in the array
 * Return: Nothing
*/
void quick_sort_recursion(int *array, int low_index, int high_index)
{
	/* stop recursion when low_index >= high_index */
	if (low_index < high_index)
	{
		int pivot_index = partition(array, low_index, high_index);

		/* apply quick_sort to the left side subarray */
		quick_sort_recursion(array, low_index, pivot_index - 1);
		print_array(array, high_index + 1);
		/* apply quick_sort to the right side subarray */
		quick_sort_recursion(array, pivot_index + 1, high_index);
		print_array(array, high_index + 1);
	}
}


/**
 * partition - function that apply swapping based on pivot
 * @array: array
 * @low_index: low index value in the array
 * @high_index: high index value in the array
 * Return: ( int ) i
*/
int partition(int *array, int low_index, int high_index)
{
	int i, j, pivot_value;

	/* get random index value between low_index value and high_index value */
	int pivot_index = low_index + (rand() % (high_index - low_index));

	/* set the pivot value at the end of the array */
	if (pivot_index != high_index)
		swap(&array[pivot_index], &array[high_index]);

	/* get the pivot value from array by high_index  */
	pivot_value = array[high_index];

	/* the position of i */
	i = low_index;
	/* start looping */
	for (j = low_index; j < high_index; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high_index]);

	return (i);
}
