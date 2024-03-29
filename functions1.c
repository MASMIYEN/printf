#include "main.h"

/**
 * printf_unsigned_int - Prints an unsigned number
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int printf_unsigned_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}


/**
 * printf_octa - Prints an unsigned number in octal notation
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int printf_octa(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}


/**
 * printf_hexadecimal - Prints an unsigned number in hexadecimal
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int printf_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * printf_hexa_upper - Prints an unsigned number in upper hexadecimal
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int printf_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * printf_hexa - Prints a hexadecimal number in lower && upper
 *
 * @types: List of arguments
 * @map_to: Array of values
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @flag_char: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 *
 * Return: Number of chars printed
 */
int printf_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_char, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}