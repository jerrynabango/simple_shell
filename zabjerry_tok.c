#include "zabjerry.h"
/**
 * tokStr - Take two ar's string
 * @program: a pointer to the program's data
 * Return: success
 */
void tokStr(list_t *program)
{
	char *ch = " \t";
	int s, j, range = 2, size;

	size = _strlen(program->prom);
	if (size)
	{
		if (program->prom[size - 1] == '\n')
			program->prom[size - 1] = '\0';
	}

	s = 0;
	while (program->prom[s])
	{
		j = 0;
		while (ch[j])
		{
			if (program->prom[s] == ch[j])
				range++;
			j++;
		}
		s++;
	}

	program->recognition = malloc(range * sizeof(char *));
	if (program->recognition == NULL)
	{
		perror(program->simple_shell);
		exit(errno);
	}
	s = 0;
	program->recognition[s] = _strdup(strtok(program->prom, ch));
	program->instruct = _strdup(program->recognition[0]);
	while (program->recognition[s++])
	{
		program->recognition[s] = _strdup(strtok(NULL, ch));
	}
}
