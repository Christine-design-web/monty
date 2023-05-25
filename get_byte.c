#include "monty.h"
#include "larez.h"
/**
 * get_func - this will select the right function
 * @parsed: the line from the bytecode file passed to main
 * Return: this is the pointer to the selected function, or NULL on failure
 */

void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};

	int codes = 17, m;

	for (m = 0; m < codes; m++)
	{
		if (strcmp(func_arr[m].opcode, parsed[0]) == 0)
		{
			return (func_arr[m].f);
		}
	}
	return (NULL);
}
/**
 * push_handler - this handles the push instruction
 * @stack: this will double the pointer to the stack to push
 * @line_number: this the number of the line in the file
 */

void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, m;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (m = 0; data.words[1][m]; m++)
	{
		if (isalpha(data.words[1][m]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);
/* the if fuction starts here */
	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
/**
 * pall_handler - tthis will handle the pall instruction
 * @stack: the double pointer to the stack to push to
 * @line_number: the number of the line in the file
 */

void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
