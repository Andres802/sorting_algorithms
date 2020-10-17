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
	int j, k;

	fwd = *list;
	while (fwd != NULL)
	{
		j = 1;
		rwd = fwd;
		
		while (rwd->prev != NULL && rwd->n < rwd->prev->n)
		{
			tmp = rwd->prev;
			/* prev = rwd - 1; next = rwd + 1 */
			if (rwd->prev->prev != NULL)
				rwd->prev->prev->next = rwd;
			
			if (rwd->next != NULL)		     /* if next is not NULL */
				rwd->next->prev = rwd->prev; /* next's previous is rwd's previous */
			
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
			j++;
			print_list(*list);
		}

		for (k = 0; k < j; k++)
			if (fwd != NULL)
				fwd = fwd->next;
	}
}
