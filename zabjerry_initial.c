#include "zabjerry.h"

/**
 * _initial - initialization of the program
 * @program: Indicates the pointer
 * @argc: Indicates the arguments
 * @argv: Array of pointers to array of chars
 * @env: Environment
 */
void _initial(list_t *program, int argc, char *argv[], char **env)
{
	int s;

	program->prom = NULL;
	program->diverge = 0;
	program->simple_shell = argv[0];
	program->instruct = NULL;
	if (argc == 1)
		program->lemma = STDIN_FILENO;
	else
	{
		program->lemma = open(argv[1], O_RDONLY);
		if (program->lemma == -1)
		{
			_print_arr(program->simple_shell);
			_print_arr(": 0: Can't open ");
			_print_arr(argv[1]);
			_print_arr("\n");
			exit(127);
		}
	}
	program->recognition = NULL;
	program->sawe = malloc(sizeof(char *) * 50);
	if (env)
	{
		s = 0;
		while (env[s])
		{
			program->sawe[s] = _strdup(env[s]);
			s++;
		}
	}
	program->sawe[s] = NULL;
	env = program->sawe;
	program->onyango = malloc(sizeof(char *) * 20);
	s = 0;
	while (s < 20)
	{
		program->onyango[s] = NULL;
		s++;
	}
}
