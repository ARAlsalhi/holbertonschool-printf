#include "main.h"

/**
 * print_zero_padding - prints zero padding
 * @width: field width
 * @len: value length
 * @buffer: pointer to buffer structure
 *
 * Return: number of characters printed
 */
int print_zero_padding(int width, int len, buffer_t *buffer)
{
	int count = 0;

	while (width > len)
	{
		count += _putchar_buffer(buffer, '0');
		width--;
	}

	return (count);
}

/**
 * number_prefix_len - returns length of sign or flag prefix
 * @num: number
 * @plus_flag: plus flag
 * @space_flag: space flag
 *
 * Return: prefix length
 */
int number_prefix_len(int num, int plus_flag, int space_flag)
{
	if (num < 0)
		return (1);
	if (plus_flag || space_flag)
		return (1);
	return (0);
}
