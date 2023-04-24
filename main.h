#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - a function to define a strct for functions and symbols
 *
 * @symb: operator
 * @func: function
 */

struct convert
{
	char *symb;
	int (*func)(va_list);
};
typedef struct convert conver_t;

/* main functions*/
int _printf(const char *format, ...);

#endif
