#include "zabjerry.h"

/**
 * ctrl_c - A function that handles ctrl_c
 *
 * Return: Empty
 */
void ctrl_c(int signal_number __attribute__((unused)))
{
	_print("\n" MSG);
}

