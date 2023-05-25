#include "monty.h"
#include "larez.h"
/**
 * rotl_handler - this will handle the rotl instruction
 * @stack: this is the double pointer to the stack to push to
 * @line_number: the number of the line in the file
 */

void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->p;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}
/**
 * rotr_handler - this will handle the rotr instruction
 * @stack: the double pointer to the stack to push to
 * @line_number: the number of the line in the file
 */

void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->p;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}
/**
 * stack_handler - this will handle the stack instruction
 * @stack: this will double point to the stack to push to
 * @line_number: the number of the line in the file
 */

void stack_handler(stack_t **stack, unsigned int line_number)
{
/* the stack for the instruction */

	(void)stack;
	(void)line_number;
	data.qflag = 0;
}

/**
 * queue_handler - this will handle the queue instruction
 * @stack: the double pointer to the stack to push to
 * @line_number: the number of the line in the file
 */

void queue_handler(stack_t **stack, unsigned int line_number)
{
/* the flag void */

	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
