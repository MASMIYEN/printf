#include "main.h"

/**
 * get_flags - Calculates active flags
 *
 * @format: Formatted string to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, jeff_i;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (jeff_i = *i + 1; format[jeff_i] != '\0'; jeff_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[jeff_i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*i = jeff_i - 1;

	return (flags);
}
