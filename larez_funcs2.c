#include "monty.h"
#include "larez.h"

/**
 * insert_dnodeint_at_index - this will insert a node at a given index
 * @b: double pointer to the list
 * @idx: index of the node to insert
 * @n: data to insert
 * Return: address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **b, unsigned int idx, int n)
{
	unsigned int m;
	dlistint_t *new;
	dlistint_t *temp = *b;

	if (idx == 0)
		return (add_dnodeint(b, n));

	for (m = 0; temp && m < idx; m++)
	{
		if (m == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(b, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !b)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - this will add a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}
/**
 * free_dlistint - this frees a doubly linked list
 * @head: pointer to the list to free
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
