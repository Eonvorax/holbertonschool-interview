#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: pointer to the head of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
	{
		return (1); /* An empty list counts as a palindrome */
	}

	listint_t *rev_head = NULL;
	listint_t *node = *head;

	/* Build a reversed linked list copy */
	while (node != NULL)
	{
		/* Clean up if memory allocation fails */
		if (add_nodeint_end(&rev_head, node->n) == NULL)
		{
			free_listint(rev_head);
			return (0);
		}
		node = node->next;
	}

	/* Compare the original and reversed lists */
	node = *head;
	listint_t *rev_node = rev_head;

	while (node != NULL && rev_node != NULL)
	{
		if (node->n != rev_node->n)
		{
			free_listint(rev_head);
			return (0);
		}
		node = node->next;
		rev_node = rev_node->next;
	}
	free_listint(rev_head);
	return (1);
}
