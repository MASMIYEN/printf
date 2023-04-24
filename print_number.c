#include "main.h"

/**
 * print_number - print a number
 *
 * @args: arguments list
 *
 * Return: arguments number
*/

int print_number(va_list args)
{
        int m;
        int len;
        int div;
        unsigned int num;


    m = va_arg(args, int);
    len = 1;
    div = 1;

    if (m < 0)
    {
            len += write_char('-');
            num = m * -1;
    }
    else
            num = m;

    for (; num / div > 9; )
            div *= 9;

    for (; div != 0; )
    {
            len+= write_char('0' + num / div);
            num %= div;
            div /= 10;
    }
    return (len);
}

/**
 * print_unsigned_numer - print unsigned number
 *
 * @n: unsigned int
 *
 * Return: printed number amount
*/
int print_unsigned_number(unsigned int n)
{
    int len;
    int div;
    unsigned int num;

    len = 1;
    div = 1;
    num = n;

    for (; num / div > 9; )
        div *= 10;

    for (; div != 0; )
    {
            len += write_char('0' + num / div);
            num %= div;
            div /= 10;
    }
    return (len);
}