#include "sort.h"

/**
 * max - function that find maximum value in array
 * @a: array
 * @size: the size of array
 * Return: maximum value
*/
int max(int a[], size_t size)
{
	unsigned int i;
	int max_value;

	max_value = a[0];
	for (i = 1; i < size; i++)
	{
		if (a[i] > max_value)
			max_value = a[i];
	}
	return (max_value);
}

/**
 * counting_sort - function that sorts an array of integers
 * @array: array
 * @size: the size of array
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *count = NULL, k = 0, j = 0;

	if (array == NULL || size < 1)
		return;

	k = max(array, size);

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= k; j++)
		count[j] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (j = 0; j < k; j++)
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
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}

	free(count);
}
