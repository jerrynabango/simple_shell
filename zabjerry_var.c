#include "zabjerry.h"

/**
 * shell_var - Indicates the shell variable
 *
 * @program: Indicates the pointer to list_t
 *
 * Return: success
 */
int shell_var(list_t *program)
{
	char *ch = NULL;
	int s;
	char str[50] = {'\0'};

	if (program->recognition[1] == NULL)
		env_output(program);
	else
	{
		s = 0;
		while (program->recognition[1][s])
		{
			if (program->recognition[1][s] == '=')
			{
				ch = _strdup(retrieve(str,
							program));
				if (ch != NULL)
					modify(str, program->recognition[1] +
							s + 1, program);
				env_output(program);
				if (retrieve(str, program) == NULL)
				{
					_print(program->recognition[1]);
					_print("\n");
				}
				else
				{
					modify(str, ch, program);
					free(ch);
				}
				return (0);
			}
			str[s] = program->recognition[1][s];
			s++;
		}
		errno = 2;
		perror(program->instruct);
		errno = 127;
	}
	return (0);
}

/**
 * shell_zed - Shell command for the specified environment
 *
 * @program: Indicates the pointer to the list_t
 *
 * Return: success
 */
int shell_zed(list_t *program)
{

	if (program->recognition[1] == NULL || program->recognition[2] == NULL)
		return (0);
	if (program->recognition[3] != NULL)
	{
		errno = E2BIG;
		perror(program->instruct);
		return (5);
	}

	modify(program->recognition[1], program->recognition[2], program);

	return (0);
}

/**
 * shell_unzed - Display the specified environment
 *
 * @program: Indicates the pointer to the list_t
 *
 * Return: success
 */
int shell_unzed(list_t *program)
{

	if (program->recognition[1] == NULL)
	{
		return (0);
	}
	if (program->recognition[2] != NULL)
	{
		errno = E2BIG;
		perror(program->instruct);
		return (5);
	}
	delete(program->recognition[1], program);

	return (0);
}
