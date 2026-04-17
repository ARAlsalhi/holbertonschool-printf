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


/**
 *print_num - prints an integer
 *@n: number to print*
 *Return: number of characters printed*/
int print_num(int n)
{
    unsigned int num;
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_num(num / 10);

    count += _putchar((num % 10) + '0');

    return (count);
}

/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print in binary
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2);

	count += _putchar((n % 2) + '0');

	return (count);
}

/**
 
print_unsigned - prints an unsigned integer
@n: number to print*
Return: number of characters printed*/
int print_unsigned(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    count += _putchar((n % 10) + '0');

    return (count);
}

//////////////////////////////////////////////////////
/**
 
print_octal - prints an unsigned int in octal
@n: number to print in octal*
Return: number of characters printed*/
int print_octal(unsigned int n)
{
    int count = 0;

    if (n / 8)
        count += print_octal(n / 8);

    count += _putchar((n % 8) + '0');

    return (count);
}

/**
 * print_hex_lower - prints an unsigned int in lowercase hexadecimal
 * @n: number to print in hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex_lower(unsigned int n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_hex_lower(n / 16);

	count += _putchar(hex[n % 16]);

	return (count);
}

/**
 * print_hex_upper - prints an unsigned int in uppercase hexadecimal
 * @n: number to print in hexadecimal
 *
 * Return: number of characters printed
 */
int print_hex_upper(unsigned int n)
{
	int count = 0;
	char *hex = "0123456789ABCDEF";

	if (n / 16)
		count += print_hex_upper(n / 16);

	count += _putchar(hex[n % 16]);

	return (count);
}
