#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: the address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL) /* Empty list, initialize circular references */
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else /* Non-empty list */
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Add new node to the start of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: the address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL) /* Empty list, initialize circular references */
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else /* Non-empty list */
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node; /* Update head pointer to new node */
	}

	return (new_node);
}
