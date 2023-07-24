#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 * @array: array
 * @size: the size of array
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *count = NULL, maximun = 0, j = 0;

	if (array == NULL || size < 2)
		return;
	maximun = array[0];
	for (; i < size; i++)
	{
		if (array[i] > maximun)
			maximun = array[i];
	}
	count = malloc(sizeof(int) * (maximun + 1));
	if (count == NULL)
		return;
	for (j = 0; j <= maximun; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 0; j < maximun; j++)
	{
		count[j + 1] += count[j];
		printf("%d, ", count[j]);
	}
	count[j + 1] += count[j];
	printf("%d\n", count[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = count[array[i]] - 1;
		if (array[i] != array[j])
		{
			maximun = array[i];
			array[i] = array[j];
			array[j] = maximun;
		}
	}

	free(count);
}

