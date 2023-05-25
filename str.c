#include "monty.h"
#include "larez.h"

/**
 * count_word - the helper of the function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */

int count_word(char *s)
{
	int flag, v, x;

	flag = 0;
	x = 0;

	for (v = 0; s[v] != '\0'; v++)
	{
		if (s[v] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			x++;
		}
	}

	return (x);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int m, l = 0, len = 0, words, v = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (m = 0; m <= len; m++)
	{
		if (isspace(str[m]) || str[m] == '\0' || str[m] == '\n')
		{
			if (v)
			{
				end = m;
				tmp = (char *) malloc(sizeof(char) * (v + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[l] = tmp - v;
				l++;
				v = 0;
			}
		}
		else if (v++ == 0)
			start = m;
	}

	matrixl[l] = NULL;

	return (matrix);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int m;

	if (!args)
		return;

	for (m = 0; args[m]; m++)
		free(args[m]);

	free(args);
}
