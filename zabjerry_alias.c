#include "zabjerry.h"

/**
 * zab_jerry - Otherwise
 * @program: Indicates a pointer to the list_t
 * @ch: Pointer to character
 * Return: success
 */
int zab_jerry(list_t *program, char *ch)
{
	char str[250] = {'\0'};
	int s, j, len;

	if (program->onyango)
	{
		len = _strlen(ch);
		s = 0;
		while (program->onyango[s])
		{
			if (!ch || (_strcmp(program->onyango[s], ch, len)
				&&	program->onyango[s][len] == '='))
			{
				j = 0;
				while (program->onyango[s][j])
				{
					str[j] = program->onyango[s][j];
					if (program->onyango[s][j] == '=')
						break;
					j++;
				}
				str[j + 1] = '\0';
				resolve(str, "'");
				resolve(str, program->onyango[s] + j + 1);
				resolve(str, "'\n");
				_print(str);
			}
			s++;
		}
	}

	return (0);
}

/**
 * ked - Otherwise
 * @program: struct for the program's data
 * @ch: ch of the requested ch.
 * Return: sucess
 */
char *ked(list_t *program, char *ch)
{
	int s = 0, len;

	if (ch == NULL || program->onyango == NULL)
		return (NULL);

	len = _strlen(ch);
	while (program->onyango[s])
	{
		if (_strcmp(ch, program->onyango[s], len) &&
			program->onyango[s][len] == '=')
		{
			return (program->onyango[s] + len + 1);
		}
		s++;
	}

	return (NULL);

}

/**
 * zed - add, or override ch
 * @ch: Pointyer to character
 * @program: Indicates pointer to the list_t
 * Return: success
 */
int zed(char *ch, list_t *program)
{
	int s = 0, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (ch == NULL ||  program->onyango == NULL)
		return (1);
	while (ch[s])
	{
		if (ch[s] != '=')
			buffer[s] = ch[s];
		else
		{
			temp = ked(program, ch + s + 1);
			break;
		}
		s++;
	}
	j = 0;
	while (program->onyango[j])
	{
		if (_strcmp(buffer, program->onyango[j], s) &&
			program->onyango[j][s] == '=')
		{
			free(program->onyango[j]);
			break;
		}
		j++;
	}
	if (temp)
	{
		resolve(buffer, "=");
		resolve(buffer, temp);
		program->onyango[j] = _strdup(buffer);
	}
	else
	{
		program->onyango[j] = _strdup(ch);
	}
	return (0);
}
