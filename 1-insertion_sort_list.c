#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to doublylinked list
 *
 * Return: no value
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *previous;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		previous = current->prev;
		while (previous != NULL && previous->n > current->n)
		{
			previous->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = previous;
			}
			current->prev = previous->prev;
			current->next = previous;

			if (previous->prev != NULL)
			{
				previous->prev->next = current;
			}
			else
			{
				*list = current;
			}
			previous->prev = current;
			previous = current->prev;
			print_list(*list);
		}
	}
}
