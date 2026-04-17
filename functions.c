#include "main.h"

char output_buffer[1024];
int buffer_index = 0;

/**
 * _putchar_buffer - adds a character to the output buffer
 * @c: character to add
 *
 * Return: 1
 */
int _putchar_buffer(char c)
{
	output_buffer[buffer_index++] = c;

	if (buffer_index >= 1024)
	{
		write(1, output_buffer, buffer_index);
		buffer_index = 0;
	}

	return (1);
}

/**
 * flush_buffer - writes remaining characters in buffer
 */
void flush_buffer(void)
{
	if (buffer_index > 0)
	{
		write(1, output_buffer, buffer_index);
		buffer_index = 0;
	}
}

/**
 * pString - prints a string
 * @string: string to print
 *
 * Return: number of characters printed
 */
int pString(char *string)
{
	int count = 0;

	if (string == NULL)
		string = "(null)";

	while (*string != '\0')
	{
		count += _putchar_buffer(*string);
		string++;
	}

	return (count);
}

/**
 * print_num - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_num(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar_buffer('-');
		num = (unsigned int)(-(long int)n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_unsigned(num / 10);

	count += _putchar_buffer((num % 10) + '0');

	return (count);
}

/**
 * print_unsigned - prints an unsigned integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);

	count += _putchar_buffer((n % 10) + '0');

	return (count);
}
