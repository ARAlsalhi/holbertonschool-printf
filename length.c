#include "main.h"

/**
 * print_long_num - prints a long integer
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_long_num(long int n, buffer_t *buffer)
{
	unsigned long int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar_buffer(buffer, '-');
		num = (unsigned long int)(-(n + 1)) + 1;
	}
	else
	{
		num = (unsigned long int)n;
	}

	if (num / 10)
		count += print_ulong(num / 10, buffer);

	count += _putchar_buffer(buffer, (num % 10) + '0');

	return (count);
}

/**
 * print_ulong - prints an unsigned long integer
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_ulong(unsigned long int n, buffer_t *buffer)
{
	int count = 0;

	if (n / 10)
		count += print_ulong(n / 10, buffer);

	count += _putchar_buffer(buffer, (n % 10) + '0');

	return (count);
}

/**
 * print_ulong_octal - prints unsigned long integer in octal
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_ulong_octal(unsigned long int n, buffer_t *buffer)
{
	int count = 0;

	if (n / 8)
		count += print_ulong_octal(n / 8, buffer);

	count += _putchar_buffer(buffer, (n % 8) + '0');

	return (count);
}

/**
 * print_ulong_hex_lower - prints unsigned long in lowercase hexadecimal
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_ulong_hex_lower(unsigned long int n, buffer_t *buffer)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_ulong_hex_lower(n / 16, buffer);

	count += _putchar_buffer(buffer, hex[n % 16]);

	return (count);
}

/**
 * print_ulong_hex_upper - prints unsigned long in uppercase hexadecimal
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_ulong_hex_upper(unsigned long int n, buffer_t *buffer)
{
	int count = 0;
	char *hex = "0123456789ABCDEF";

	if (n / 16)
		count += print_ulong_hex_upper(n / 16, buffer);

	count += _putchar_buffer(buffer, hex[n % 16]);

	return (count);
}
