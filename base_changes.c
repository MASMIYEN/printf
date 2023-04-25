#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int hexCheck(int, char);

/**
 * print_binary - number converter to binary
 *
 * @list: arguments list
 *
 * Return: number length
*/

int print_binary(va_list list)
{
    int m, len;
    unsigned int num;
    char *str;
    char *revStr;

}

num = va_arg(list, unsigned int);
    if (num  < 1)
        return (-1);
    if (num == 0)
        return (write_char('0'));

len = base_len(num, 2);
str = malloc(sizeof(char) * (len + 1));

if (str == NULL)
    return (-1);

    for (m = 0; num > 0; m++)
        {
            if (num % 2 == 0)
                str[m] = '0';
            else
                str[m] = '1';
            num = num / 2;

            str[m] = '\0';
            revStr = rev_string(str);
            if (revStr == NULL)
                return (-1);
            write_base(revStr);
            free(str);
            free(revStr);
            return (len);
        }

/**
 * print_octal - print number in octal format
 *
 * @list arguments list
 *
 * Return: Symbols number
*/
int print_octal(va_list list)
{
	int len;
    unsigned int num;
	char *octal_rep;
	char *revStr;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (write_char('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';
	rev_str = rev_string(octal_rep);
	if (revStr == NULL)
		return (-1);

	write_base(revStr);
	free(octal_rep);
	free(revStr);
	return (len);
}