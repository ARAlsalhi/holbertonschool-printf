#include "main.h"

/**
 * print_reverse - prints a string in reverse
 * @string: string to reverse
 * @buffer: pointer to buffer
 *
 * Return: number of characters printed
 */
int print_reverse(char *string, buffer_t *buffer)
{
	int count = 0;
	int len = 0;

	if (string == NULL)
		string = "(null)";

	while (string[len] != '\0')
		len++;

	while (len > 0)
	{
		len--;
		count += _putchar_buffer(buffer, string[len]);
	}

	return (count);
}
