#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string
 * @i: pointer to a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR[] = {FMINUS, FPLUS, FZERO, FHASH, FSPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; CH[j] != '\0'; j++)
			if (format[curr_i] == CH[j])
			{
				flags |= ARR[j];
				break;
			}

		if (CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
