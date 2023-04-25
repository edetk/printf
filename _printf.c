#include "main.h"

void print_buffer(char buffer[], int *buf_count);

/**
 * _printf - Printf function
 * @format: format.
 * Return: count of chars.
 */
int _printf(const char *format, ...)
{
	int i, count = 0, char_return = 0;
	int flags, width, precision, size, buf_count = 0;
	va_list lists;
	char buffer[BUF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buf_count++] = format[i];
			if (buf_count == BUF_SIZE)
				print_buffer(buffer, &buf_count);
			char_return++;
		}
		else
		{
			if (format[i + 1] == 'r')
			{
				handle_r(buffer, &buf_count);
				i += 1;
			}
			else
			{
				print_buffer(buffer, &buf_count);
				flags = get_flags(format, &i);
				width = get_width(format, &i, lists);
				precision = get_precision(format, &i, lists);
				size = get_size(format, &i);
				++i;
				count = handle_print(format, &i, lists, buffer,
				flags, width, precision, size);
				if (count == -1)
					return (-1);
				char_return += count;
			}
		}
	}

	print_buffer(buffer, &buf_count);

	va_end(lists);

	return (char_return);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buf_count: Index at which to add next char, represents the len.
 */
void print_buffer(char buffer[], int *buf_count)
{
	if (*buf_count > 0)
		write(1, &buffer[0], *buf_count);

	*buf_count = 0;
}
