#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - Struct op
 *
 * @frmt: The format.
 * @fnc: The function associated.
 */
struct frmt
{
	char frmt;
	int (*fnc)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct frmt frmt_t - Struct op
 *
 * @frmt: The format.
 * @frm_t: The function associated.
 */
typedef struct frmt frmt_t;

int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** Functions ******************/

/* print chars and strings */
int printf_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print numbers */
int printf_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_unsigned_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_octa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printf_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_char, int width, int precision, int size);

/* print non printable characters */
int printf_unprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print memory address */
int printf_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* other specifiers */
int find_flags(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int find_precision(const char *format, int *i, va_list list);
int find_size(const char *format, int *i);

/* print string in reverse*/
int printf_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print a string in rot 13*/
int printf_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char bffr[], int flags, int width, int precision,
	int length, char padding, char extra_ch);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padding, char extra_ch, int padding_start);

int write_unsigned(int is_negative, int index,
char buffer[],
	int flags, int width, int precision, int size);

/****************** additional ******************/
int is_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);

long int cnvrt_size_num(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif