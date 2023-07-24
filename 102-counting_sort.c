#include "sort.h"

/**
 * max - function that finds the maximum value in the array
 * @a: array
 * @size: the size of the array
 * Return: maximum value
 */
int max(int a[], size_t size)
{
    unsigned int i;
    int max_value = a[0];

    for (i = 0; i < size; i++)
    {
        if (a[i] > max_value)
            max_value = a[i];
    }
    return (max_value);
}

/**
 * counting_sort - function that sorts an array of integers
 * @array: array
 * @size: the size of the array
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
    unsigned int i = 0;
    int *count = NULL, k = 0, j = 0;

    if (array == NULL || size < 2)
        return;

    k = max(array, size);

    count = malloc(sizeof(int) * (k + 1));
    if (count == NULL)
        return;

    for (j = 0; j <= k; j++)
        count[j] = 0;

    for (i = 0; i < size; i++)
        count[array[i]] += 1;

    for (j = 1; j <= k; j++) // Change j < k to j <= k
    {
        count[j] += count[j - 1]; // Update counting array
        printf("%d, ", count[j - 1]); // Print the counting array
    }

    printf("%d\n", count[j - 1]); // Print the last element of the counting array

    int *output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i < size; i++)
    {
        output_array[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(output_array);
    free(count);
}
