#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;

	/* Using Knuth sequence to initialize gap */
	while (gap < size)
		gap = gap * 3 + 1;

	/* Reduce the gap in each loop */
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		/* Perform insertion sort on each subarray */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
