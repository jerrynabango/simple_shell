#include "zabjerry.h"

/**
 * frequent - free recurrent
 * @program: a pointer to list_t
 * Return: Empty
 */
void frequent(list_t *program)
{
	if (program->prom)
		free(program->prom);
	if (program->instruct)
		free(program->instruct);
	if (program->recognition)
		free_arr(program->recognition);

	program->recognition = NULL;
	program->prom = NULL;
	program->instruct = NULL;
}

/**
 * long_str - string from number.
 * @num: parameter.
 * @str: save a number as string.
 * @base: base to number
 *
 * Return: Empty.
 */
void long_str(long num, char *str, int base)
{
	int neg = 0;
	char l[] = "0123456789abcdef";
	int s = 0;


	if (str[0] == '-')
		neg = 1;

	if (num == 0)
		str[s++] = '0';

	for (; num != 0; num /= base)
	{
		if (num < 0)
			str[s++] = l[-(num % base)];
		else
			str[s++] = l[num % base];
	}
	if (neg)
		str[s++] = '-';

	str[s] = '\0';

	_strrev(str);
}


/**
 * freedom - free all
 * @program: a pointer to list_t
 * Return: Empty
 */
void freedom(list_t *program)
{
	if (program->lemma != 0)
	{
		if (close(program->lemma))
			perror(program->simple_shell);
	}
	frequent(program);
	free_arr(program->onyango);
	free_arr(program->sawe);
}

/**
 * _count - count string that repeat
 * @str: pointer to str origen.
 * @ch: string with  chars to be counted
 * Return: count.
 */
int _count(char *str, char *ch)
{
	int s;
	int j;

	s = 0;
	j = 0;
	while (str[s])
	{
		if (str[s] == ch[0])
			j++;
		s++;
	}
	return (j);
}

/**
 * free_arr - free array pointer
 * @arr: array of pointers
 * Return: Empty
 */
void free_arr(char **arr)
{
	int s;

	if (arr != NULL)
	{
		s = 0;
		while (arr[s])
		{
			free(arr[s]);
			s++;
		}

		free(arr);
		arr = NULL;
	}
}
