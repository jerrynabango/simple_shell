#include "zabjerry.h"

/**
 * _find - find path
 * @program: a pointer to list_t
 * Return: 0 or error
 */
int _find(list_t *program)
{
	int s = 0;
	char firstChar = program->instruct[0];
	int rtn = 0;
	char **folder;

	if (firstChar == '/' || firstChar == '.')
		return (inspect(program->instruct));

	if (program->instruct == NULL)
		return (2);

	free(program->recognition[0]);

	program->recognition[0] = _strcat(_strdup("/"), program->instruct);
	if (program->recognition[0] == NULL)
		return (2);
	folder = tok(program);
	if (folder == NULL || !folder[0])
	{
		errno = 127;
		return (127);
	}
	while (folder[s] != NULL)
	{
		folder[s] = _strcat(folder[s], program->recognition[0]);
		rtn = inspect(folder[s]);
		if (rtn == 0 || rtn == 126)
		{
			errno = 0;
			free(program->recognition[0]);
			program->recognition[0] = _strdup(folder[s]);
			free_arr(folder);
			return (rtn);
		}
		s++;
	}
	free(program->recognition[0]);
	program->recognition[0] = NULL;
	free_arr(folder);
	return (rtn);
}

/**
 * tok - function to index path
 * @program: a pointer to list_t
 * Return: path folder
 */
char **tok(list_t *program)
{
	char **tok = NULL;
	int s;
	char *track;
	int enum_dir = 2;

	track = retrieve("PATH", program);
	if (track == NULL || track[0] == '\0')
	{
		return (NULL);
	}

	track = _strdup(track);

	s = 0;
	while (track[s] != '\0')
	{
		if (track[s] == ':')
		{
			enum_dir++;
		}

		s++;
	}

	tok = malloc(sizeof(char *) * enum_dir);

	s = 0;
	tok[s] = _strdup(strtok(track, ":"));

	for (s = 1; tok[s - 1] != NULL; s++)
	{
		tok[s] = _strdup(strtok(NULL, ":"));
	}


	free(track);
	track = NULL;
	return (tok);

}

/**
 * inspect - checks file
 * @ch: pointer parameter
 * Return: 0 or error
 */
int inspect(char *ch)
{
	struct stat four;

	if (stat(ch, &four) != -1)
	{
		if (S_ISDIR(four.st_mode) ||	access(ch, X_OK) != 0)
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
