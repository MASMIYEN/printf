#include "main.h"

/**
 * write_char - write char c to stdout
 *
 * @c: char to print
 *
 * Return: 1 Success, -1 On error
*/
int write_char(char c)
{
    return (write(1, &c, 1));
}