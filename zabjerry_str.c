#include "zabjerry.h"

/**
 * _strlen - count string length
 * @str: parameter
 * Return: String length
 */
int _strlen(char *str)
{
	int s;

	if (str == NULL)
		return (0);

	for (s = 0; str[s] != '\0'; s++)
		;

	return (s);
}

/**
 * _strdup - duplicate
 * @str: parameter
 * Return: array pointer
 */
char *_strdup(char *str)
{
	int s;
	char *ch;
	int j;

	if (str == NULL)
		return (NULL);

	j = _strlen(str) + 1;

	ch = malloc(sizeof(char) * j);

	if (ch == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	s = 0;
	while (s < j)
	{
		ch[s] = str[s];
		s++;
	}

	return (ch);
}

/**
 * _strcmp - Compare
 * @s1: parameter
 * @s2: parameter
 * @num: characters len to be compared
 * Return: 1 or 0
 */
int _strcmp(char *s1, char *s2, int num)
{
	int s;

	if (s1 == NULL || s2 == NULL)
		return (0);

	if (s1 == NULL && s2 == NULL)
		return (1);

	if (num == 0)
	{
		if (_strlen(s1) != _strlen(s2))
			return (0);

		s = 0;
		while (s1[s])
		{
			if (s1[s] != s2[s])
				return (0);
			s++;
		}
		return (1);
	}
	else
	{
		s = 0;
		while (s < num)
		{
			if (s1[s] != s2[s])
				return (0);
			s++;
		}
		return (1);
	}
}

/**
 * _strcat - joins two strings.
 * @s1: parameter
 * @s2: parameter
 * Return: array pointer
 */
char *_strcat(char *s1, char *s2)
{
	char *eq;
	int l1 = 0, l2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	l1 = _strlen(s1);
	l2 = _strlen(s2);

	eq = malloc(sizeof(char) * (l1 + l2 + 1));
	if (eq == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	l1 = 0;
	while (s1[l1] != '\0')
	{
		eq[l1] = s1[l1];
		l1++;
	}
	free(s1);

	l2 = 0;
	while (s2[l2] != '\0')
	{
		eq[l1] = s2[l2];
		l1++;
		l2++;
	}

	eq[l1] = '\0';
	return (eq);
}


/**
 * _strrev - reverse
 * @str: parameter.
 * Return: Nothing
 */
void _strrev(char *str)
{

	int s;
	char hold;
	int j;

	j = _strlen(str) - 1;
	s = 0;
	while (s < j)
	{
		hold = str[s];
		str[s++] = str[j];
		str[j--] = hold;
	}
}
