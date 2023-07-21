#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array that will be sorted
 * @size: array size
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, j;

	for (index = 0; index < size; index++)
	{
		for (j = 0; j < (size - 1 - index); j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}

}

