#include "zabjerry.h"

/**
 * retrieve - Extract input
 * @ch: Indicates the pointer to character
 * @program: Indicates the pointer to the list_t
 * Return: Success
 */
char *retrieve(char *ch, list_t *program)
{
	int range;
	int s;

	if (program->sawe == NULL)
	{
		return (NULL);
	}

	if (ch == NULL)
		return (NULL);

	range = _strlen(ch);
	s = 0;
	while (program->sawe[s])
	{
		if (_strcmp(ch, program->sawe[s], range) &&
		 program->sawe[s][range] == '=')
		{
			return (program->sawe[s] + range + 1);
		}
		s++;
	}
	return (NULL);
}

/**
 * modify - Perform new updates
 * @ch: Indicates pointer to character
 * @str: Indicates character
 * @program: Indicates the pointer to list_t
 * Return: Success
 */

int modify(char *ch, char *str, list_t *program)
{
	int s, range = 0, initialize = 1;

	if (program->sawe == NULL)
		return (1);
	if (str == NULL)
		return (1);
	if (ch == NULL || str == NULL || program->sawe == NULL)
		return (1);

	range = _strlen(ch);
	s = 0;
	while (program->sawe[s])
	{
		if (_strcmp(ch, program->sawe[s], range) &&
		 program->sawe[s][range] == '=')
		{
			initialize = 0;
			free(program->sawe[s]);
			break;
		}
		s++;
	}
	program->sawe[s] = _strcat(_strdup(ch), "=");
	program->sawe[s] = _strcat(program->sawe[s], str);

	if (initialize)
	{
		program->sawe[s + 1] = NULL;
	}
	return (0);
}

/**
 * delete - Delete character
 * @ch: Indicates the pointer to the character
 * @program: Indicates the pointer
 * Return: success;
 */
int delete(char *ch, list_t *program)
{
	int range, s;

	if (program->sawe == NULL)
		return (0);
	if (ch == NULL || program->sawe == NULL)
		return (0);

	range = _strlen(ch);
	s = 0;
	while (program->sawe[s] != NULL)
	{
		if (_strcmp(ch, program->sawe[s], range) &&
		 program->sawe[s][range] == '=')
		{
			free(program->sawe[s]);

			while (program->sawe[s] != NULL)
			{
				program->sawe[s] = program->sawe[s + 1];
				s++;
			}
			program->sawe[s] = NULL;
			return (1);
		}
		s++;
	}
	return (0);
}


/**
 * env_output - Displays the output
 * @program: Indicates the pointer to list_t
 * Return: Empty
 */
void env_output(list_t *program)
{
	int j = 0;

	while (program->sawe[j])
	{
		_print(program->sawe[j]);
		_print("\n");
	}
	j++;
}
