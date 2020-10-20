#include "sort.h"

void sort(int *array, size_t lo, size_t hi, size_t size);
size_t partition(int *array, size_t lo, size_t hi, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm and Lomuto partitioning scheme.
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1 && array != NULL)
		sort(array, 0, size - 1, size);
}

/**
 * sort - recursive function implementing Quick sort algorithm.
 * @array: Array to sort.
 * @lo: Lowest index.
 * @hi: Highest index.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void sort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i_pivot;

	if (lo < hi)
	{
		i_pivot = partition(array, lo, hi, size);

		if (i_pivot > 0)
			sort(array, lo, i_pivot - 1, size);

		if (i_pivot < size - 1)
			sort(array, i_pivot + 1, hi, size);
	}
}

/**
 * partition - implements Lomuto partitioning scheme.
 * @array: Array to sort.
 * @lo: Lowest index.
 * @hi: Highest index.
 * @size: Size of the array.
 *
 * Return: Correct index for pivot.
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	size_t i_pivot, i_sort;
	int pivot, tmp;

	pivot = array[hi];
	i_pivot = lo;

	for (i_sort = lo; i_sort < hi; i_sort++)
	{
		if (array[i_sort] < pivot)
		{
			tmp = array[i_pivot];
			array[i_pivot] = array[i_sort];
			array[i_sort] = tmp;
			if (i_sort != i_pivot && array[i_sort] != array[i_pivot])
				print_array(array, size);
			i_pivot++;
		}
	}
	tmp = array[i_pivot];
	array[i_pivot] = array[hi];
	array[hi] = tmp;
	if (i_sort != i_pivot && array[i_sort] != array[i_pivot])
		print_array(array, size);
	return (i_pivot);
}
