#include "zabjerry.h"

/**
* _kedrine - Display output
* @program: Indicates the pointer to the list_t
*
* Return: succes
*/
int _kedrine(list_t *program)
{
	static char oper[10] = {'\0'};
	char ch[BUFFER_SIZE] = {'\0'};
	ssize_t scan, s = 0;
	static char *cmd[10] = {NULL};


	if (!cmd[0] || (oper[0] == '&' && errno != 0) ||
		(oper[0] == '|' && errno == 0))
	{
		s = 0;
		while (cmd[s])
		{
			free(cmd[s]);
			cmd[s] = NULL;
			s++;
		}
		scan = read(program->lemma, &ch, BUFFER_SIZE - 1);
		if (scan == 0)
			return (-1);

		s = 0;
		do {
			cmd[s] = _strdup(strtok(s ? NULL : ch, "\n;"));
			s = scan_kendrine(cmd, s, oper);
		} while (cmd[s++]);
	}

	program->prom = cmd[0];
	s = 0;
	while (cmd[s])
	{
		cmd[s] = cmd[s + 1];
		oper[s] = oper[s + 1];
		s++;
	}

	return (_strlen(program->prom));
}


/**
* scan_kendrine - Scan a kendrine
* @cmd: array of the commands.
* @s: index in the cmd to be checked
* @oper: array of the logical operators for each previous command
*
* Return: success
*/
int scan_kendrine(char *cmd[], int s, char oper[])
{
	int j = 0;
	char *ch = NULL;

	while (cmd[s] != NULL  && cmd[s][j])
	{
		if (cmd[s][j] == '&' && cmd[s][j + 1] == '&')
		{
			ch = cmd[s];
			cmd[s][j] = '\0';
			cmd[s] = _strdup(cmd[s]);
			cmd[s + 1] = _strdup(ch + j + 2);
			s++;
			oper[s] = '&';
			free(ch);
			j = 0;
		}
		if (cmd[s][j] == '|' && cmd[s][j + 1] == '|')
		{
			ch = cmd[s];
			cmd[s][j] = '\0';
			cmd[s] = _strdup(cmd[s]);
			cmd[s + 1] = _strdup(ch + j + 2);
			s++;
			oper[s] = '|';
			free(ch);
			j = 0;
		}
		j++;
	}
	return (s);
}
