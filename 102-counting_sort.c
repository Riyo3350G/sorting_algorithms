#include "sort.h"

/**
 * max_val - Get the maximum value in an array of ints.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: The max value integer in the array.
 */
int max_val(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: no return(void)
 */
void counting_sort(int *array, size_t size)
{
	int *ctr, *sorted_arr;
	int max_value, i;

	if (array == NULL || size < 2)
		return;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return;
	max_value = max_val(array, size);
	ctr = malloc(sizeof(int) * (max_value + 1));
	if (ctr == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		ctr[i] = 0;
	for (i = 0; i < (int)size; i++)
		ctr[array[i]] += 1;
	for (i = 0; i < (max_value + 1); i++)
		ctr[i] += ctr[i - 1];
	print_array(ctr, max_value + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[ctr[array[i]] - 1] = array[i];
		ctr[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(ctr);
}
