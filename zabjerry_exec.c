#include "zabjerry.h"

/**
 * execution - Performs execution of a shell command
 * @program: Indicates the pointer to the program
 * Return: 0 or error
 */
int execution(list_t *program)
{
	pid_t my_pid;
	int state;
	int retval = 0;

	retval = implicit(program);
	if (retval != -1)
		return (retval);

	retval = _find(program);
	if (retval)
	{
		return (retval);
	}
	else
	{
		my_pid = fork();
		if (my_pid == -1)
		{
			perror(program->instruct);
			exit(EXIT_FAILURE);
		}
		if (my_pid == 0)
		{
			retval = execve(program->recognition[0], program->recognition,
					program->sawe);
			if (retval == -1)
				perror(program->instruct), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&state);
			if (WIFEXITED(state))
				errno = WEXITSTATUS(state);
			else if (WIFSIGNALED(state))
				errno = 128 + WTERMSIG(state);
		}
	}
	return (0);
}
