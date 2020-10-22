#include "sort.h"

/*size_t power(size_t n);
void insertion_sort(int *array, size_t size);
int sorted(int *array, size_t size);*/

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence.
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t gap, i_gap, i_sort;

	if (size < 2 || array == NULL)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		continue;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i_gap = gap; i_gap < size; i_gap++)
		{
			tmp = array[i_gap];
			for (i_sort = i_gap;
			     i_sort > gap - 1 && array[i_sort - gap] >= tmp;
			     i_sort -= gap)
			{
				array[i_sort] = array[i_sort - gap];
			}
			array[i_sort] = tmp;
		}
		print_array(array, size);
	}
}
