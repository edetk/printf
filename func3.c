#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @lists: lists a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list lists, char buffer[],
	int flags, int width, int precision, int size)
{
	char added_c = 0, padd = ' ';
	int ind = BUF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(lists, void *);

	IDLE(width);
	IDLE(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUF_SIZE - 1] = '\0';
	IDLE(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & FZERO) && !(flags & FMINUS))
		padd = '0';
	if (flags & FPLUS)
		added_c = '+', len++;
	else if (flags & FSPACE)
		added_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, len,
		width, flags, padd, added_c, padd_start));
}

/**
 * non_prints - Prints ascii codes in hexa of non printable chars
 * @lists: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int non_prints(va_list lists, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(lists, char *);

	IDLE(flags);
	IDLE(width);
	IDLE(precision);
	IDLE(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @lists: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list lists, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	IDLE(buffer);
	IDLE(flags);
	IDLE(width);
	IDLE(size);

	str = va_arg(lists, char *);

	if (str == NULL)
	{
		IDLE(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @lists: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list lists, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(lists, char *);
	IDLE(buffer);
	IDLE(flags);
	IDLE(width);
	IDLE(precision);
	IDLE(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				x = output[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
