#ifndef ZABJERRY_H
#define ZABJERRY_H

#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define PATH_JERRY "setenv=\n"
#define PATH_SIMPLE "cd=\n"
#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MSG "zablon@jerry$ "
#define QUIT "exit=\n"
#define PATH1 "help=\n"
#define SIMPLE_PATH "unsetenv=\n"
#define PATH_ZAB "env=\n"

/**
 * struct done- information
 *
 * @simple_shell: parameter
 *
 * @prom: parameter
 *
 * @instruct: parameter
 *
 * @diverge: parameter
 *
 * @lemma: parameter
 *
 * @recognition: parameter
 *
 * @sawe: parameter
 *
 * @onyango: parameter
 */
typedef struct done
{
	char **recognition;
	char **sawe;
	char *simple_shell;
	int lemma;
	char **onyango;
	char *prom;
	char *instruct;
	int diverge;
} list_t;

/**
 * struct jerz - structure
 *
 * @jerzab: parameter
 *
 * @seven: function
 */
typedef struct jerz
{
	char *jerzab;
	int (*seven)(list_t *program);
} six;

int otherwise(list_t *program);
int shell_var(list_t *program);
int implicit(list_t *program);
int inspect(char *ch);
char *retrieve(char *name, list_t *program);
int modify(char *key, char *value, list_t *program);
int delete(char *key, list_t *program);
int status(list_t *program);
int swit(list_t *program, char *ch);
int simply(list_t *program);
char **tok(list_t *program);
int _find(list_t *program);
int resolve(char *buffer, char *str_to_add);
void tokStr(list_t *program);
int execution(list_t *program);
void env_output(list_t *program);
int _print(char *str);
int _print_arr(char *str);
int _print_err(int errcode, list_t *program);
int _strlen(char *ch);
void free_arr(char **arr);
void frequent(list_t *program);
void freedom(list_t *program);
int emanation(list_t *program);
int shell_zed(list_t *program);
int shell_unzed(list_t *program);
void _initial(list_t *program, int arc, char *argv[], char **env);
void _info(char *input, list_t *program);
int _kedrine(list_t *program);
int scan_kendrine(char *array_commands[], int i, char array_operators[]);
void process(list_t *program);
void substitute(list_t *program);
char *_strcat(char *s1, char *s2);
void _strrev(char *str);
void long_str(long num, char *str, int base);
int _atoi(char *ch);
int _count(char *string, char *character);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2, int num);
int zab_jerry(list_t *program, char *ch);
char *ked(list_t *program, char *ch);
int zed(char *ch, list_t *program);
void ctrl_c(int signal_number __attribute__((unused)));

#endif
