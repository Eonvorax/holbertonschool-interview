#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	/* Any empty or single-node list is a palindrome */
	if (!head || !*head || !(*head)->next)
		return (1);

	listint_t *slow = *head, *fast = *head, *first_half, *second_half;

	/* Use slow and fast pointers to find the middle of the list */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse the second half of the list */
	second_half = reverse_list(slow);
	first_half = *head;

	/* Compare the first half and the reversed second half */
	listint_t *temp = second_half;

	while (temp)
	{
		if (first_half->n != temp->n)
		{
			/* Restore the list before returning */
			reverse_list(second_half);
			return (0);
		}
		first_half = first_half->next;
		temp = temp->next;
	}

	/* Restore the list to its original state and return */
	reverse_list(second_half);
	return (1);
}
