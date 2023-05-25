#include "monty.h"

/**
 * dlistint_len - this will return the number of nodes in a doubly linked list
 * @b: pointer to the list
 * Return: the number of nodes
 */

size_t dlistint_len(const dlistint_t *b)
{
	size_t nodes = 0;

	if (!b)
		return (0);

	while (b)
	{
		nodes++;
		b = b->next;
	}

	return (nodes);
}

/**
 * add_dnodeint -  this adds a new node at the beginning of a doubly linked list
 * @head: the double pointer to the list
 * @p: data to insert in the new node
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int p)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = p;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}
/**
 * print_dlistint - this prints a doubly linked list
 * @b: the pointer to the list
 * Return: number of nodes in the list
 */

size_t print_dlistint(const dlistint_t *b)
{
	size_t nodes = 0;

	if (!b)
		return (0);

	while (b)
	{
		printf("%d\n", b->p);
		p = p->next;
		nodes++;
	}

	return (nodes);
}
/**
 * delete_dnodeint_at_index -  this will delete a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int m = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (m < index)
	{
		temp = temp->next;
		m++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}
/**
 * get_dnodeint_at_index - this will get the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 * Return: address of the node, or if it does not exist, NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int m = 0;

	if (!head)
		return (NULL);

	while (head && m < index)
	{
		head = head->next;
		m++;
	}
/* who knows */
	return (head ? head : NULL);
}
