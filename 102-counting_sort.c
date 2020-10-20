#include "sort.h"

size_t maximum(int *a, size_t s);

/**
  * counting_sort - sorts an array of integers in ascending order using
  * the Counting sort algorithm
  * @array: array
  * @size: size of array
  *
  * Return: nothing
  */
void counting_sort(int *array, size_t size)
{

	int *a_count, *a_sorted;
	size_t index, max;

	max = maximum(array, size);
	a_sorted = malloc(sizeof(int) * size);
	if (!a_sorted)
		return;
	a_count = malloc(sizeof(int) * (max + 1));
	if (!a_count)
		return;

	for (index = 0; index <= max; index++)
		a_count[index] = 0;

	for (index = 0; index < size; index++)
		a_count[array[index]]++;

	for (index = 0; index <= max; index++)
		if (index + 1 <= max)
			a_count[index + 1] += a_count[index];

	print_array(a_count, max + 1);
	for (index = 0; index < size; index++)
	{
		if (a_count[array[index]] > 0)
		{
			a_sorted[a_count[array[index]] - 1] = array[index];
			a_count[array[index]]--;
		}
	}
	for (index = 0; index < size; index++)
		array[index] = a_sorted[index];
	free(a_sorted);
	free(a_count);
}

/**
  * maximum - return the biggest number
  * @a: array
  * @s: size of the array
  *
  * Return: max
  */
size_t maximum(int *a, size_t s)
{
	size_t max, i;

	for (i = 0; i < s; i++)
	{
		if (i == 0)
			max = a[i];
		else if ((int)max < a[i])
			max = a[i];
	}
	return (max);
}
