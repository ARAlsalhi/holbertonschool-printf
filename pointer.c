#include "main.h"

/**
 * print_pointer_hex - prints pointer value in hexadecimal
 * @n: pointer value as unsigned long int
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
static int print_pointer_hex(unsigned long int n, buffer_t *buffer)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_pointer_hex(n / 16, buffer);

	count += _putchar_buffer(buffer, hex[n % 16]);

	return (count);
}

/**
 * print_pointer - prints a pointer address
 * @ptr: pointer to print
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_pointer(void *ptr, buffer_t *buffer)
{
	int count = 0;
	unsigned long int address;

	if (ptr == NULL)
		return (pString("(nil)", buffer));

	address = (unsigned long int)ptr;

	count += _putchar_buffer(buffer, '0');
	count += _putchar_buffer(buffer, 'x');
	count += print_pointer_hex(address, buffer);

	return (count);
}
