#include "main.h"

/**
 * print_char - print a character
 *
 * @list: a list of arguments
 *
 * Return: amount of characters printed
*/

int print_char(va_list list)
{
    write_char(va_arg(list, int));
    return (1);
}

/**
 * print_string - print a string
 *
 * @list: a list of arguments
 *
 * Return: amount of characters printed
*/

int print_string(va_list list)
{
    int m;
    char *str;

    str = va_arg(list, char *);
    if (str == NULL)
        str = "(null)";
    for (m = 0; str[m] != '\0'; m++)
        write_char(str[m]);
    return (m);
}

/**
 * print_percent - print a percentage
 * @list: a list of arguments
 *
 * Return: amount of characters printed
*/

int print_percent(__attribute__((unused)) va_list list)
{
    write_char('%');
    return (1);
}

/**
 * print_integer - print an integer
 *
 * @list: a list of arguments
 *
 * Return: amount of characters printed
*/

int print_integer(va_list list)
{
    int num_length = print_number(list);

    return (num_length);
}

/**
 * unsigned_int - print an unsigned integer
 *
 * @list: a list of arguments
 *
 * Return: numbers count
*/

int unsigned_int(va_list list)
{
    unsigned int num = va_arg(list, unsigned int);

    if (num < 1)
        return (-1);

    if (num == 0)
        return (print_unsigned_number(num))
}