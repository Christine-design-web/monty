#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* larez_funcs1.c */
size_t dlistint_len(const dlistint_t *b);
dlistint_t *add_dnodeint(dlistint_t **head, const int p);
size_t print_dlistint(const dlistint_t *b);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/* larez_funcs2.c */

dlistint_t *insert_dnodeint_at_index(dlistint_t **b, unsigned int idx, int p);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int p);
void free_dlistint(dlistint_t *head);

#endif
