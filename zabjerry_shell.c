#include "zabjerry.h"

/**
 * main - Entry point
 * @argc: Indicates n.o of arguments
 * @argv: Argument vector
 * @env: Variable enviroment
 * Return: Always 0(success)
 */
int main(int argc, char *argv[], char *env[])
{

	char *input = "";
	list_t program_struct = {NULL}, *program = &program_struct;

	_initial(program, argc, argv, env);

	signal(SIGINT, ctrl_c);

	if (isatty(STDIN_FILENO))
	{
		if (isatty(STDOUT_FILENO))
		{
			if (argc == 1)
			{
				errno = 2;
				input = MSG;
			}
		}
	}

	errno = 0;
	_info(input, program);
	return (0);
}

/**
 * _print - print out
 * @str: parameter
 * Return: number of bytes.
 */
int _print(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}
/**
 * _print_arr - print array of chars
 * @str: parameter
 * Return: number of bytes
 */
int _print_arr(char *str)
{
	return (write(STDERR_FILENO, str, strlen(str)));
}

/**
 * _atoi - convert string.
 *
 * @ch: a pointer to string
 * Return: i * s
 */
int _atoi(char *ch)
{
	int s = 1, i = 0;

	for (; !('0' <= *ch && *ch <= '9') && *ch != '\0'; ch++)
	{
		if (*ch == '+')
			s *= +1;
		if (*ch == '-')
			s *= -1;
	}

	for (; '0' <= *ch && *ch <= '9' && *ch != '\0'; ch++)
	{

		i = (i * 10) + (*ch - '0');
	}
	return (i * s);
}

/**
 * _print_err - print a array of chars
 * @program: a pointer to list_t
 * @errcode: error code
 * Return: number of bytes
 */
int _print_err(int errcode, list_t *program)
{
	char str[] = "";

	long_str((long) program->diverge, str, 10);

	if (errcode == 2 || errcode == 3)
	{
		_print_arr(program->simple_shell);
		_print_arr(": ");
		_print_arr(str);
		_print_arr(": ");
		_print_arr(program->recognition[0]);
		if (errcode == 2)
			_print_arr(": Illegal number: ");
		else
			_print_arr(": can't cd to ");
		_print_arr(program->recognition[1]);
		_print_arr("\n");
	}
	else if (errcode == 127)
	{
		_print_arr(program->simple_shell);
		_print_arr(": ");
		_print_arr(str);
		_print_arr(": ");
		_print_arr(program->instruct);
		_print_arr(": not found\n");
	}
	else if (errcode == 126)
	{
		_print_arr(program->simple_shell);
		_print_arr(": ");
		_print_arr(str);
		_print_arr(": ");
		_print_arr(program->instruct);
		_print_arr(": Permission denied\n");
	}
	return (0);
}
