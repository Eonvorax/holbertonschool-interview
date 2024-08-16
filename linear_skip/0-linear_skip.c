#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Integer value to search for
 *
 * Return: Pointer to first node where value is found, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (list == NULL)
		return (NULL);

	skiplist_t *fast = list;
	skiplist_t *slow = list;

	/* Go through the express lane first */
	while (fast->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   fast->express->index, fast->express->n);
		if (fast->express->n >= value)
			break;
		fast = fast->express;
	}

	slow = fast;
	if (fast->express == NULL)
	{
		/* Express lane exhausted, search from last node in the express lane */
		while (fast->next != NULL)
			fast = fast->next;
	}
	else
	{
		/* Express lane not exhausted, so set slow to the current position */
		fast = fast->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		   slow->index, fast->index);

	/* Linear search between slow and fast */
	while (slow != NULL && slow->index <= fast->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", slow->index, slow->n);
		if (slow->n == value)
			return (slow);
		slow = slow->next;
	}
	return (NULL);
}
