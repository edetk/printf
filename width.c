#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: lists of arguments to be printed.
 * @lists: lists of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list lists)
{
	int ind;
	int width = 0;

	for (ind = *i + 1; format[ind] != '\0'; ind++)
	{
		if (is_digit(format[ind]))
		{
			width *= 10;
			width += format[ind] - '0';
		}
		else if (format[ind] == '*')
		{
			ind++;
			width = va_arg(lists, int);
			break;
		}
		else
			break;
	}

	*i = ind - 1;

	return (width);
}
