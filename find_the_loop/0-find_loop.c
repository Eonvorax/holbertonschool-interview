#include "lists.h"

/**
 * find_listint_loop - finds a loop in a linked list
 * @head: the head of the list to search
 *
 * Return: address of node where the loop starts or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL)
		return (NULL);

	listint_t *slow = head;
	listint_t *fast = head;

	/* Floyd's Tortoise and Hare algorithm */
	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		/* Did we find a loop ? */
		if (fast == slow)
		{
			/* Reset the slow pointer to the start of the list */
			slow = head;
			/* Move the pointers again, both at the same speed this time */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			/* The pointers meet at the start of the loop */
			return (slow);
		}
	}
	return (NULL);
}
