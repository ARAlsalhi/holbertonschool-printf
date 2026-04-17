#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string containing the format
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int plus_flag, space_flag, hash_flag;
	char length_mod;
	buffer_t buffer;

	buffer.index = 0;

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

			plus_flag = 0;
			space_flag = 0;
			hash_flag = 0;
			length_mod = '\0';

			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
					plus_flag = 1;
				else if (*format == ' ')
					space_flag = 1;
				else if (*format == '#')
					hash_flag = 1;
				format++;
			}

			if (*format == 'l' || *format == 'h')
			{
				length_mod = *format;
				format++;
			}

			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (*format)
			{
				case 'c':
					count += _putchar_buffer(&buffer, va_arg(args, int));
					break;
				case 's':
					count += pString(va_arg(args, char *), &buffer);
					break;
				case 'S':
					count += print_string_custom(va_arg(args, char *), &buffer);
					break;
				case 'd':
				case 'i':
					if (length_mod == 'l')
						count += print_long_num(va_arg(args, long int), &buffer);
					else if (length_mod == 'h')
						count += print_num((short int)va_arg(args, int), &buffer);
					else
						count += print_num(va_arg(args, int), &buffer);
					break;
				case '%':
					count += _putchar_buffer(&buffer, '%');
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int), &buffer);
					break;
				case 'u':
					if (length_mod == 'l')
						count += print_ulong(va_arg(args,
							unsigned long int), &buffer);
					else if (length_mod == 'h')
						count += print_unsigned((unsigned short int)
							va_arg(args, unsigned int), &buffer);
					else
						count += print_unsigned(va_arg(args,
							unsigned int), &buffer);
					break;
				case 'o':
					if (length_mod == 'l')
						count += print_ulong_octal(va_arg(args,
							unsigned long int), &buffer);
					else if (length_mod == 'h')
						count += print_octal((unsigned short int)
							va_arg(args, unsigned int), &buffer);
					else
						count += print_octal(va_arg(args,
							unsigned int), &buffer);
					break;
				case 'x':
					if (length_mod == 'l')
						count += print_ulong_hex_lower(va_arg(args,
							unsigned long int), &buffer);
					else if (length_mod == 'h')
						count += print_hex_lower((unsigned short int)
							va_arg(args, unsigned int), &buffer);
					else
						count += print_hex_lower(va_arg(args,
							unsigned int), &buffer);
					break;
				case 'X':
					if (length_mod == 'l')
						count += print_ulong_hex_upper(va_arg(args,
							unsigned long int), &buffer);
					else if (length_mod == 'h')
						count += print_hex_upper((unsigned short int)
							va_arg(args, unsigned int), &buffer);
					else
						count += print_hex_upper(va_arg(args,
							unsigned int), &buffer);
					break;
				case 'p':
					count += print_pointer(va_arg(args, void *), &buffer);
					break;
				default:
					count += _putchar_buffer(&buffer, '%');
					if (plus_flag)
						count += _putchar_buffer(&buffer, '+');
					if (space_flag)
						count += _putchar_buffer(&buffer, ' ');
					if (hash_flag)
						count += _putchar_buffer(&buffer, '#');
					count += _putchar_buffer(&buffer, *format);
					break;
			}
		}
		else
		{
			count += _putchar_buffer(&buffer, *format);
		}

		format++;
	}

	flush_buffer(&buffer);
	va_end(args);

	return (count);
}
