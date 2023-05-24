#include "zabjerry.h"

/**
 * emanation - vent
 *
 * @program: Indicates the pointer to the list_t
 *
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int emanation(list_t *program)
{
	int s = 0;

	if (program->recognition[1] != NULL)
	{
		while (program->recognition[1][s])
		{
			if ((program->recognition[1][s] < '0' || program->recognition[1][s] > '9')
				&& program->recognition[1][s] != '+')
			{
				errno = 2;
				return (2);
			}
			s++;
		}
		errno = _atoi(program->recognition[1]);
	}
	freedom(program);
	exit(errno);
}

/**
 * status - Show current path
 *
 * @program: Indicates the pointer to the List_t
 *
 * Return: success
 */
int status(list_t *program)
{
	char  *zedj = NULL;
	char *ch = retrieve("HOME", program);
	char jer[128] = {0};
	int ret = 0;

	if (program->recognition[1])
	{
		if (_strcmp(program->recognition[1], "-", 0))
		{
			zedj = retrieve("OLDPWD", program);
			if (zedj)
			{
				ret = swit(program, zedj);
			}
			_print(retrieve("PWD", program));
			_print("\n");

			return (ret);
		}
		else
		{
			return (swit(program, program->recognition[1]));
		}
	}
	else
	{
		if (!ch)
		{
			ch = getcwd(jer, 128);
		}

		return (swit(program, ch));
	}
	return (0);
}

/**
 * swit - set the work directory
 *
 * @program: Indicates the pointer to the list_t
 *
 * @ch: Indicates the pointer to the character
 *
 * Return: success
 */
int swit(list_t *program, char *ch)
{
	int identifier = 0;
	char jer[128] = {0};

	getcwd(jer, 128);

	if (!_strcmp(jer, ch, 0))
	{
		identifier = chdir(ch);
		if (identifier == -1)
		{
			errno = 2;
			return (3);
		}
		modify("PWD", ch, program);
	}
	modify("OLDPWD", jer, program);
	return (0);
}

/**
 * simply - shows the environment where the shell runs
 *
 * @program: Indicates a pointer to the list_t
 *
 * Return: success
 */
int simply(list_t *program)
{
	char *ch[6] = {NULL};
	int j = 0, s = 0;

	ch[0] = PATH1;
	if (program->recognition[1] == NULL)
	{
		_print(ch[0] + 6);
		return (1);
	}
	if (program->recognition[2] != NULL)
	{
		errno = E2BIG;
		perror(program->instruct);
		return (5);
	}
	ch[1] = QUIT;
	ch[2] = PATH_ZAB;
	ch[3] = PATH_JERRY;
	ch[4] = SIMPLE_PATH;
	ch[5] = PATH_SIMPLE;

	while (ch[s])
	{
		j = _strlen(program->recognition[1]);
		if (_strcmp(program->recognition[1], ch[s], j))
		{
			_print(ch[s] + j + 1);
			return (1);
		}
		s++;
	}

	errno = EINVAL;
	perror(program->instruct);
	return (0);
}

/**
 * otherwise - common or different
 *
 * @program: Indicates the pointer to the list_t
 *
 * Return: success
 */
int otherwise(list_t *program)
{
	int s;

	if (program->recognition[1] == NULL)
	{
		return (zab_jerry(program, NULL));
	}
	s = 0;
	while (program->recognition[++s])
	{
		if (_count(program->recognition[s], "="))
		{
			zed(program->recognition[s], program);
		}
		else
		{
			zab_jerry(program, program->recognition[s]);
		}
	}

	return (0);
}
