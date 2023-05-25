#include "monty.h"
#include "larez.h"

/**
 * pint_handler - this will handle the pint instruction
 * @stack: this will double pointer to the stack to push
 * @line_number: the number of the line in the file
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}
/* this will print to the terminal */
	printf("%d\n", head->n);
}

/**
 * pop_handler - this will handle the pop instruction
 * @stack: the double pointer to the stack to push
 * @line_number: the number of the line in the file
 */

void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
/* the if function to ouput the temp starts here */

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}
/**
 * swap_handler - this will handle the swap instruction
 * @stack: the double pointer to the stack to push
 * @line_number: number of the line in the file
 */

void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;
/* the num if fuction starts here*/

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
/**
 * add_handler - this will handle the add instruction
 * @stack: the double pointer to the stack to push
 * @line_number: the number of the line in the file
 */

void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop_handler - this will handle the nop instruction
 * @stack: the double pointer to the stack to push to
 * @line_number: the number of the line in the file
 */

void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
