#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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

	while (*string)
	{
		count += _putchar(*string);
		string++;
	}

	return (count);
}
