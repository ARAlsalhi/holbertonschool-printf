#include "main.h"

/**
 * string_len - returns length of string
 * @string: string
 *
 * Return: length
 */
int string_len(char *string)
{
	int len = 0;

	if (string == NULL)
		return (6);

	while (string[len])
		len++;

	return (len);
}

/**
 * unsigned_len - returns length of unsigned int in decimal
 * @n: number
 *
 * Return: length
 */
int unsigned_len(unsigned int n)
{
	int len = 1;

	while (n >= 10)
	{
		n /= 10;
		len++;
	}

	return (len);
}

/**
 * signed_len - returns length of int (with sign)
 * @n: number
 *
 * Return: length
 */
int signed_len(int n)
{
	int len = 1;

	if (n < 0)
		len++;

	while (n <= -10 || n >= 10)
	{
		n /= 10;
		len++;
	}

	return (len);
}

/**
 * base_len - returns length of number in a given base
 * @n: number
 * @base: base to use
 *
 * Return: length
 */
int base_len(unsigned int n, int base)
{
	int len = 1;

	while (n >= (unsigned int)base)
	{
		n /= base;
		len++;
	}

	return (len);
}

/**
 * print_padding - prints spaces before value
 * @width: field width
 * @len: value length
 * @buffer: buffer
 *
 * Return: number of characters printed
 */
int print_padding(int width, int len, buffer_t *buffer)
{
	int count = 0;

	while (width > len)
	{
		count += _putchar_buffer(buffer, ' ');
		width--;
	}

	return (count);
}
