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
	int ctbuffer[2];
	int ctbuffer3[2];
	char copyarray[10000];
	char *copyfrmt;
	va_list args;

	count = &ctbuffer[2];
	count3 = &ctbuffer3[2];
	count[0] = 0;
	count[1] = -1;
	if (format != NULL)
	{
		count[1] = 0;
		copyfrmt = _strcpy(copyarray, format);
		va_start(args, format);
		while (copyfrmt[m] != '\0')
		{
			if (copyfrmt[m] == '%')
			{
				count3 = print_formats(m, copyfrmt, args);
				if (count3[1] == -1)
					return (-1);
				count[1] += count3[1];
				m += count[0];
			}
			else
			{
				count[1] += _putchar(&copyfrmt[1]);
			}
			m++;
		}
		va_end(args);
	}
	return (count[1]);
}

