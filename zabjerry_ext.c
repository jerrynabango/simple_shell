#include "zabjerry.h"

void processCommands(char *cmd, list_t *program);
void updateInputLine(char *cmd, list_t *program);

/**
 * process - process cmd line
 * @program: Indicates the pointer to the program
 *
 * Return: Empty
 */
void process(list_t *program)
{
	char cmd[BUFFER_SIZE] = {0};

	if (program->prom == NULL)
		return;

	resolve(cmd, program->prom);

	processCommands(cmd, program);
	updateInputLine(cmd, program);
}
/**
 * processCommands - ......
 *
 *@cmd: ....
 *
 *@program: ....
 *
 * Return: Empty
*/
void processCommands(char *cmd, list_t *program)
{
	int s = 0, j;
	char *sub, size[BUFFER_SIZE] = {'\0'};

	while (cmd[s])
	{
		if (cmd[s] == '#')
			cmd[s--] = '\0';
		else if (cmd[s] == '$' && cmd[s + 1] == '?')
		{
			cmd[s] = '\0';
			long_str(errno, size, 10);
			resolve(cmd, size);
			resolve(cmd, program->prom + s + 2);
		}
		else if (cmd[s] == '$' && cmd[s + 1] == '$')
		{
			cmd[s] = '\0';
			long_str(getpid(), size, 10);
			resolve(cmd, size);
			resolve(cmd, program->prom + s + 2);
		}
		else if (cmd[s] == '$' && (cmd[s + 1] == ' ' || cmd[s + 1] == '\0'))
			continue;
		else if (cmd[s] == '$')
		{
			for (j = 1; cmd[s + j] && cmd[s + j] != ' '; j++)
				size[j - 1] = cmd[s + j];
			sub = retrieve(size, program);
			cmd[s] = '\0', size[0] = '\0';
			resolve(size, cmd + s + j);
			sub ? resolve(cmd, sub) : 1;
			resolve(cmd, size);
		}
		s++;
	}
}
/**
 *updateInputLine - ...
 *
 *@cmd: ..
 *
 *@program: ..
 *
 * Return: Empty
*/
void updateInputLine(char *cmd, list_t *program)
{
	if (!_strcmp(program->prom, cmd, 0))
	{
		free(program->prom);
		program->prom = _strdup(cmd);
	}
}
/**
 * substitute - Process cmd
 * @program: Indicates the pointer to the program
 *
 * Return: Empty
 */
void substitute(list_t *program)
{
	char *sub;
	char size[BUFFER_SIZE] = {'\0'};
	char cmd[BUFFER_SIZE] = {0};

	int s, j;
	int tute = 0;

	if (program->prom == NULL)
		return;

	resolve(cmd, program->prom);
	s = 0;
	while (cmd[s])
	{
		j = 0;
		while (cmd[s + j] && cmd[s + j] != ' ')
		{
			size[j] = cmd[s + j];
			j++;
		}
		size[j] = '\0';
		sub = ked(program, size);
		if (sub)
		{
			size[0] = '\0';
			resolve(size, cmd + s + j);
			cmd[s] = '\0';
			resolve(cmd, sub);
			cmd[_strlen(cmd)] = '\0';
			resolve(cmd, size);
			tute = 1;
		}
		break;
		s++;
	}
	if (tute)
	{
		free(program->prom);
		program->prom = _strdup(cmd);
	}
}

/**
 * resolve - append string at end of the barrier
 * @barrier: Indicate pointer to barrier
 * @con_str: Indicate
 * Return: nothing, but sets errno.
 */
int resolve(char *barrier, char *con_str)
{
	int range, s;

	range = _strlen(barrier);
	s = 0;
	while (con_str[s])
	{
		barrier[range + s] = con_str[s];
		s++;
	}
	barrier[range + s] = '\0';
	return (range + s);
}
