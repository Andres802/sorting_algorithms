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
	int i, j, k;

	i = 1;

	fwd = *list;
	while (fwd != NULL)
	{
		j = 1;
		rwd = fwd;
		printf("\n--- [ %.02d - fwd.n = %d ] ---\n", i, fwd->n);
		printf("\nbefore: ");
		print_list(*list);
		if (rwd->prev != NULL)
			printf("rwd.n = [ %d < %d ] = rwd.prev.n\n", rwd->n, rwd->prev->n);
		printf("J = %d\n\n", j);
		while (rwd->prev != NULL && rwd->n < rwd->prev->n)
		{
			printf("--- [ %.02d | %.02d ] ---\n", i, j);
			/* prev = rwd - 1; next = rwd + 1 */
			printf("1 ");
			if (rwd->prev->prev != NULL)
				rwd->prev->prev->next = rwd;
			printf("2 ");
			if (rwd->next != NULL)		     /* if next is not NULL */
				rwd->next->prev = rwd->prev; /* next's previous is rwd's previous */
			printf("3 ");
			if (rwd->prev != NULL)
			{
				rwd->prev->next = rwd->next;
				printf("4 ");
				rwd->prev = rwd->prev->prev;
			}
			printf("5 ");
			if (rwd->next != NULL)
				rwd->next = rwd->next->prev;
			printf("6 ");
			if (rwd->next != NULL)
				rwd->next->prev = rwd;
			printf("7\n");
			if (rwd->prev == NULL)
				*list = rwd;

			printf("after: ");
			print_list(*list);
			if (rwd->prev != NULL)
				printf("rwd.n = [ %d < %d ] = rwd.prev.n\n", rwd->n, rwd->prev->n);
			j++;
			printf("J = %d\n\n", j);
		}
		i++;
		for (k = 0; k < j; k++)
			if (fwd != NULL)
				fwd = fwd->next;
	}
}
