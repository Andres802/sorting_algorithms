#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: list to sort
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *fwd, *rwd, *tmp;
	int i_fwd, i_rwd;

	fwd = *list;
	while (fwd != NULL)
	{
		i_rwd = 1;
		rwd = fwd;
		while (rwd->prev != NULL && rwd->n < rwd->prev->n)
		{
			tmp = rwd->prev;
			if (rwd->prev->prev != NULL)
				rwd->prev->prev->next = rwd;
			if (rwd->next != NULL)
				rwd->next->prev = rwd->prev;
			if (rwd->prev != NULL)
			{
				rwd->prev->next = rwd->next;
				rwd->prev = rwd->prev->prev;
			}
			if (rwd->next != NULL)
				rwd->next = rwd->next->prev;
			if (rwd->next != NULL)
				rwd->next->prev = rwd;
			if (rwd->next == NULL)
			{
				rwd->next = tmp;
				tmp->prev = rwd;
			}
			if (rwd->prev == NULL)
				*list = rwd;
			i_rwd++;
			print_list(*list);
		}
		for (i_fwd = 0; i_fwd < i_rwd; i_fwd++)
			if (fwd != NULL)
				fwd = fwd->next;
	}
}
