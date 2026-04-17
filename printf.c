#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string containing the format
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += pString(va_arg(args, char *));
					break;
				case 'd':
					count += print_num(va_arg(args, int));
					break;	
				case 'i':
					count += print_num(va_arg(args, int));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal(va_arg(args, unsigned int));
					break;
				case 'x':
					count += print_hex_lower(va_arg(args, unsigned int));
					break;
				case 'X':
					count += print_hex_upper(va_arg(args, unsigned int));
					break;	
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return (count);
}
