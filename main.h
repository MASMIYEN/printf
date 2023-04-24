#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - a function to define a struct for functions and symbols
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
int parser(const char *format, conver_t func_list[], va_list arg_list);
int write_char(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_int(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

/*Additional functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);

#endif
