#include "sort.h"
/**
 * bubble_sort - sorting bubble sort algo
 * @array: array input
 * @size: array size n elements
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t j;
	unsigned int unsorted;

	if (array == NULL || size < 2)
		return;

	unsorted  = 1;
	while (unsorted)
	{
		unsorted = 0;
		for (j = 0; j < size; j++)
			if (j < size - 1 && array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				unsorted = 1;
				print_array(array, size);
			}

	}
}
