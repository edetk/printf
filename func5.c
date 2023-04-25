/**
 * handle_r - Handles the %r format specifier
 * @buffer: Array of chars
 * @buf_count: Index at which to add next char, represents the len.
 * Return: 0
 */
int handle_r(char buffer[], int *buf_count)
{
	buffer[(*buf_count)++] = '%';
	buffer[(*buf_count)++] = 'r';

	return (0);
}

