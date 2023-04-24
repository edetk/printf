#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: lists of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int ind = *i + 1;
	int size = 0;

	if (format[ind] == 'l')
		size = SLONG;
	else if (format[ind] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ind - 1;
	else
		*i = ind;

	return (size);
}
