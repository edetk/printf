#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: lists of arguments to be printed.
 * @lists: lists of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list lists)
{
	int ind = *i + 1;
	int precision = -1;

	if (format[ind] != '.')
		return (precision);

	precision = 0;

	for (ind += 1; format[ind] != '\0'; ind++)
	{
		if (is_digit(format[ind]))
		{
			precision *= 10;
			precision += format[ind] - '0';
		}
		else if (format[ind] == '*')
		{
			ind++;
			precision = va_arg(lists, int);
			break;
		}
		else
			break;
	}

	*i = ind - 1;

	return (precision);
}
