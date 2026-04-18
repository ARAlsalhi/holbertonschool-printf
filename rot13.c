#include "main.h"

/**
 * print_rot13 - prints a string encoded with rot13
 * @string: string to encode
 * @buffer: pointer to buffer
 *
 * Return: number of characters printed
 */
int print_rot13(char *string, buffer_t *buffer)
{
	int count = 0;
	char c;

	if (string == NULL)
		string = "(null)";

	while (*string != '\0')
	{
		c = *string;

		if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
			c += 13;
		else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
			c -= 13;

		count += _putchar_buffer(buffer, c);
		string++;
	}

	return (count);
}
