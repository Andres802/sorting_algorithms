#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 * @array: The arrey to sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i_main, i_sub, i_min;
	int tmp;

	for (i_main = 0; i_main < size - 1; i_main++)
	{
		i_min = i_main;

		for (i_sub = i_main; i_sub < size; i_sub++)
			if (array[i_sub] < array[i_min])
				i_min = i_sub;

		if (i_min != i_main)
		{
			tmp = array[i_main];
			array[i_main] = array[i_min];
			array[i_min] = tmp;
			print_array(array, size);
		}
	}
}
