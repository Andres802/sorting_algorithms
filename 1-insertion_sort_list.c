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
	listint_t *fwd, *rwd;
	int i;

	fwd = *list;

	while (fwd != NULL)
	{
		rwd = fwd;
		while (rwd->prev != NULL && rwd->n < rwd->prev->n)
		{
			i = 0;
			printf("%d#  ", i++);
			print_list(*list);
			/* prev = rwd - 1; next = rwd + 1 */
			if (rwd->next != NULL) /* if next is not NULL */
				rwd->next->prev = rwd->prev; /* next's previous
							* is rwd's previous
							*/
			printf("%d#  ", i++);
			print_list(*list);
			rwd->prev->next = rwd->next;
			printf("%d#  ", i++);
			print_list(*list);
			rwd->prev = rwd->prev->prev;
			printf("%d#  ", i++);
			print_list(*list);
			rwd->next = rwd->next->prev;
			printf("%d#  ", i++);
			print_list(*list);
			rwd->next->prev = rwd;
			printf("%d#  ", i++);
			print_list(*list);
			rwd = rwd->prev;
		}
		fwd = fwd->next;
	}
}
