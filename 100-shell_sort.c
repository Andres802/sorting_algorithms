#include "sort.h"

size_t power(size_t n);
void insertion_sort(int *array, size_t size);
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
	size_t i_gap, i_sort, i_next, i_prev, gap;

	if (size < 2 && array == NULL)
		return;

	for (i_gap = 1; i_gap < size; i_gap++)
		if ((power(i_gap) - 1) / 2 > size)
			break;

	i_gap--;
	for (; i_gap > 0; i_gap--)
	{
		if (i_gap == 1)
		{
			insertion_sort(array, size);
			print_array(array, size);
		}
		else
		{
			gap = (power(i_gap) - 1) / 2;
			for (i_sort = 0; i_sort < i_gap; i_sort++)
			{
				for (i_next = i_sort + gap, i_prev = i_sort;
				     i_next < size;
				     i_next += gap, i_prev += gap)
				{
					if (array[i_prev] > array[i_next])
					{
						tmp = array[i_prev];
						array[i_prev] = array[i_next];
						array[i_next] = tmp;
					}
				}
			}
			print_array(array, size);
		}
	}
}

/**
 * power - calculate 3 raised to @n power.
 * @n: Power.
 *
 * Return: 3 raised to @n power.
 */
size_t power(size_t n)
{
	size_t power = 1;

	for (; n > 0; n--)
		power *= 3;

	return power;
}

/**
 * insertion_sort - sorts a array of integers in ascending order using
 * the Insertion sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void insertion_sort(int *array, size_t size)
{
	size_t i_main, i_sort;
	int tmp;

	for (i_main = 0; i_main < size; i_main++)
	{
		for (i_sort = i_main;
		     i_sort > 0 && array[i_sort] < array[i_sort - 1];
		     i_sort--)
		{
			tmp = array[i_sort - 1];
			array[i_sort - 1] = array[i_sort];
			array[i_sort] = tmp;
		}
	}
}
