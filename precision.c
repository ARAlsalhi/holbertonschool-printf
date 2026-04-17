#include "main.h"

/**
 * print_repeat - prints a character multiple times
 * @buffer: pointer to buffer structure
 * @c: character to print
 * @count: number of times to print
 *
 * Return: number of characters printed
 */
int print_repeat(buffer_t *buffer, char c, int count)
{
	int printed = 0;

	while (count > 0)
	{
		printed += _putchar_buffer(buffer, c);
		count--;
	}

	return (printed);
}

/**
 * print_string_precision - prints string with precision
 * @string: string to print
 * @precision: maximum chars to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_string_precision(char *string, int precision, buffer_t *buffer)
{
	int count = 0;

	if (string == NULL)
		string = "(null)";

	while (*string != '\0' && (precision < 0 || count < precision))
	{
		count += _putchar_buffer(buffer, *string);
		string++;
	}

	return (count);
}

/**
 * value_len_precision - returns digit length with precision
 * @n: number
 * @base: number base
 * @precision: requested precision
 *
 * Return: resulting length
 */
int value_len_precision(unsigned int n, int base, int precision)
{
	int len;

	if (precision == 0 && n == 0)
		return (0);

	len = base_len(n, base);

	if (precision > len)
		return (precision);

	return (len);
}

/**
 * print_value_precision - prints unsigned value with precision
 * @n: number to print
 * @base: number base
 * @digits: digits table
 * @precision: requested precision
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_value_precision(unsigned int n, int base, char *digits,
	int precision, buffer_t *buffer)
{
	int count = 0;
	int len;

	if (precision == 0 && n == 0)
		return (0);

	len = base_len(n, base);

	if (precision > len)
		count += print_repeat(buffer, '0', precision - len);

	if (base == 10)
		count += print_unsigned(n, buffer);
	else if (base == 8)
		count += print_octal(n, buffer);
	else if (digits[10] == 'a')
		count += print_hex_lower(n, buffer);
	else
		count += print_hex_upper(n, buffer);

	return (count);
}
