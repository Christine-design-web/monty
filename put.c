#include "monty.h"
#include "larez.h"

/**
 * pchar_handler - this will handle the pchar instruction
 * @stack: this is the double pointer to the stack to push
 * @line_number: the number of the line in the file
 */

void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->p < 0 || node->p > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->p);
	putchar('\n');
}
/**
 * pstr_handler - this will handle the pstr instruction
 * @stack: the double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->p != 0 && node->p >= 0 && node->p <= 127)
	{
		putchar(node->p);
		node = node->next;
	}

	putchar('\n');
}
