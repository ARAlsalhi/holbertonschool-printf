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
	int width;
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
			width = 0;
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

			while (*format >= '0' && *format <= '9')
			{
				width = (width * 10) + (*format - '0');
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
				{
					int len = 1;

					count += print_padding(width, len, &buffer);
					count += _putchar_buffer(&buffer, va_arg(args, int));
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					int len = string_len(str);

					count += print_padding(width, len, &buffer);
					count += pString(str, &buffer);
					break;
				}
				case 'S':
					count += print_string_custom(va_arg(args, char *), &buffer);
					break;
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					int len = signed_len(num);

					count += print_padding(width, len, &buffer);
					count += print_num(num, &buffer);
					break;
				}
				case '%':
					count += print_padding(width, 1, &buffer);
					count += _putchar_buffer(&buffer, '%');
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int), &buffer);
					break;
				case 'u':
				{
					unsigned int num = va_arg(args, unsigned int);
					int len = unsigned_len(num);

					count += print_padding(width, len, &buffer);
					count += print_unsigned(num, &buffer);
					break;
				}
				case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);
					int len = unsigned_len(num);

					count += print_padding(width, len, &buffer);
					count += print_octal(num, &buffer);
					break;
				}
				case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);
					int len = unsigned_len(num);

					count += print_padding(width, len, &buffer);
					count += print_hex_lower(num, &buffer);
					break;
				}
				case 'X':
				{
					unsigned int num = va_arg(args, unsigned int);
					int len = unsigned_len(num);

					count += print_padding(width, len, &buffer);
					count += print_hex_upper(num, &buffer);
					break;
				}
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
					if (length_mod != '\0')
						count += _putchar_buffer(&buffer, length_mod);
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
