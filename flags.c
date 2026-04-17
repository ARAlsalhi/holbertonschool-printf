#include "main.h"

/**
 * print_num_flags - prints signed number with + or space flag
 * @n: number to print
 * @plus_flag: prints + before positive numbers
 * @space_flag: prints space before positive numbers
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_num_flags(int n, int plus_flag, int space_flag, buffer_t *buffer)
{
	int count = 0;

	if (n < 0)
		return (print_num(n, buffer));

	if (plus_flag)
		count += _putchar_buffer(buffer, '+');
	else if (space_flag)
		count += _putchar_buffer(buffer, ' ');

	count += print_unsigned((unsigned int)n, buffer);

	return (count);
}

/**
 * print_octal_flag - prints octal number with # flag
 * @n: number to print
 * @hash_flag: enables # flag behavior
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_octal_flag(unsigned int n, int hash_flag, buffer_t *buffer)
{
	int count = 0;

	if (hash_flag && n != 0)
		count += _putchar_buffer(buffer, '0');

	count += print_octal(n, buffer);

	return (count);
}

/**
 * print_hex_lower_flag - prints lowercase hex number with # flag
 * @n: number to print
 * @hash_flag: enables # flag behavior
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_hex_lower_flag(unsigned int n, int hash_flag, buffer_t *buffer)
{
	int count = 0;

	if (hash_flag && n != 0)
	{
		count += _putchar_buffer(buffer, '0');
		count += _putchar_buffer(buffer, 'x');
	}

	count += print_hex_lower(n, buffer);

	return (count);
}

/**
 * print_hex_upper_flag - prints uppercase hex number with # flag
 * @n: number to print
 * @hash_flag: enables # flag behavior
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_hex_upper_flag(unsigned int n, int hash_flag, buffer_t *buffer)
{
	int count = 0;

	if (hash_flag && n != 0)
	{
		count += _putchar_buffer(buffer, '0');
		count += _putchar_buffer(buffer, 'X');
	}

	count += print_hex_upper(n, buffer);

	return (count);
}
