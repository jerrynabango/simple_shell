#include "zabjerry.h"

/**
 * implicit - Similar
 *
 * @program: Indicates the pointer to the list_t
 *
 * Return: success
 **/
int implicit(list_t *program)
{
	int s;
	six options[] = {
		{"exit", emanation},
		{"help", simply},
		{"cd", status},
		{"alias", otherwise},
		{"env", shell_var},
		{"setenv", shell_unzed},
		{"unsetenv", shell_unzed},
		{NULL, NULL}
	};

	s = 0;
	while (options[s].jerzab != NULL)
	{
		if (_strcmp(options[s].jerzab, program->instruct, 0))
		{
			return (options[s].seven(program));
		}
		s++;
	}
	return (-1);
}
