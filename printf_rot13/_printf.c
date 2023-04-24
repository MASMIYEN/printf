#include "main.h"

/**
 * _printf - printf clone
 *
 * @format: const ptr to a char
 *
 * Return: printed chars number
 */

int _printf(const char *format, ...)
{
	int m = 0, *count, *count3;
	int cntBuffer[2];
	int cntBuffer3[2];
	char copyArray[10000];
	char *copyFormat;
	va_list args;

	count = &cntBuffer[2];
	count3 = &cntBuffer[2];
	count[0] = 0;
	count[1] = -1;
	if (format != NULL)
	{
		count[1] = 0;
		copyFormat = _strcpy(copyArray, format);
		va_start(args, format);
		while (copyFormat[m] != '\0')
		{
			if (copyFormat[m] == '%')
			{
				count3 = print_formats(m, copyFormat, args);
				if (count3[1] == -1)
					return (-1);
				count[1] += count3[1];
				m += count[0];
			}
			else
			{
				count[1] += _putchar(&copyFormat[1]);
			}
			m++;
		}
		va_end(args);
	}
	return (count[1]);
}

