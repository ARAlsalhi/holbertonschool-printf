#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print in binary
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n, buffer_t *buffer)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2, buffer);

	count += _putchar_buffer(buffer, (n % 2) + '0');

	return (count);
}

/**
 * print_octal - prints an unsigned int in octal
 * @n: number to print in octal
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n, buffer_t *buffer)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8, buffer);

	count += _putchar_buffer(buffer, (n % 8) + '0');

	return (count);
}

/**
 * print_hex_lower - prints an unsigned int in lowercase hexadecimal
 * @n: number to print in hexadecimal
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_hex_lower(unsigned int n, buffer_t *buffer)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_hex_lower(n / 16, buffer);

	count += _putchar_buffer(buffer, hex[n % 16]);

	return (count);
}

/**
 * print_hex_upper - prints an unsigned int in uppercase hexadecimal
 * @n: number to print in hexadecimal
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_hex_upper(unsigned int n, buffer_t *buffer)
{
	int count = 0;
	char *hex = "0123456789ABCDEF";

	if (n / 16)
		count += print_hex_upper(n / 16, buffer);

	count += _putchar_buffer(buffer, hex[n % 16]);

	return (count);
}

/**
 * print_string_custom - prints string with non-printable chars in hex
 * @string: string to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_string_custom(char *string, buffer_t *buffer)
{
	int count = 0;
	unsigned char c;
	char *hex = "0123456789ABCDEF";

	if (string == NULL)
		string = "(null)";

	while (*string != '\0')
	{
		c = (unsigned char)*string;

		if ((c > 0 && c < 32) || c >= 127)
		{
			count += _putchar_buffer(buffer, '\\');
			count += _putchar_buffer(buffer, 'x');
			count += _putchar_buffer(buffer, hex[c / 16]);
			count += _putchar_buffer(buffer, hex[c % 16]);
		}
		else
		{
			count += _putchar_buffer(buffer, c);
		}

		string++;
	}

	return (count);
}
