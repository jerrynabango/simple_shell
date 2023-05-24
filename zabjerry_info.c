#include "zabjerry.h"

/**
 * _info - Indicates loop
 * @input: User input/prompt message
 * @program: Pointer to list_t
 * Return: Empty
 */
void _info(char *input, list_t *program)
{
	int err = 0;
	int len = 0;

	for (program->diverge = 0; ; (program->diverge)++)
	{
		_print(input);
		err = len = _kedrine(program);

		if (err == EOF)
		{
			freedom(program);
			exit(errno);
		}
		if (len >= 1)
		{
			substitute(program);
			process(program);
			tokStr(program);
			if (program->recognition[0])
			{
				err = execution(program);
				if (err != 0)
					_print_err(err, program);
			}
			frequent(program);
		}
	}
}
