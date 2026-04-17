#include "main.h"

/**
 * _putchar_buffer - adds a character to the output buffer
 * @buffer: pointer to buffer structure
 * @c: character to add
 *
 * Return: 1
 */
int _putchar_buffer(buffer_t *buffer, char c)
{
	buffer->output[buffer->index] = c;
	buffer->index++;

	if (buffer->index >= 1024)
		flush_buffer(buffer);

	return (1);
}

/**
 * flush_buffer - writes remaining characters in buffer
 * @buffer: pointer to buffer structure
 */
void flush_buffer(buffer_t *buffer)
{
	if (buffer->index > 0)
	{
		write(1, buffer->output, buffer->index);
		buffer->index = 0;
	}
}

/**
 * pString - prints a string
 * @string: string to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int pString(char *string, buffer_t *buffer)
{
	int count = 0;

	if (string == NULL)
		string = "(null)";

	while (*string != '\0')
	{
		count += _putchar_buffer(buffer, *string);
		string++;
	}

	return (count);
}

/**
 * print_num - prints an integer
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_num(int n, buffer_t *buffer)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar_buffer(buffer, '-');
		num = (unsigned int)(-(long int)n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_unsigned(num / 10, buffer);

	count += _putchar_buffer(buffer, (num % 10) + '0');

	return (count);
}

/**
 * print_unsigned - prints an unsigned integer
 * @n: number to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n, buffer_t *buffer)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10, buffer);

	count += _putchar_buffer(buffer, (n % 10) + '0');

	return (count);
}
