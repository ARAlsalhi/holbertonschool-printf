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
	int width, precision, has_precision;
	int len, total_len, prefix_len;
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
			precision = 0;
			has_precision = 0;
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

			if (*format == '*')
			{
				width = va_arg(args, int);
				if (width < 0)
					width = 0;
				format++;
			}
			else
			{
				while (*format >= '0' && *format <= '9')
				{
					width = (width * 10) + (*format - '0');
					format++;
				}
			}

			if (*format == '.')
			{
				has_precision = 1;
				format++;

				if (*format == '*')
				{
					precision = va_arg(args, int);
					if (precision < 0)
					{
						has_precision = 0;
						precision = 0;
					}
					format++;
				}
				else
				{
					precision = 0;
					while (*format >= '0' && *format <= '9')
					{
						precision = (precision * 10) + (*format - '0');
						format++;
					}
				}
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
					len = 1;
					count += print_padding(width, len, &buffer);
					count += _putchar_buffer(&buffer, va_arg(args, int));
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					len = string_len(str);

					if (has_precision && precision < len)
						len = precision;

					count += print_padding(width, len, &buffer);
					count += print_string_precision(str,
						has_precision ? precision : -1, &buffer);
					break;
				}
				case 'S':
					count += print_string_custom(va_arg(args, char *), &buffer);
					break;
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					unsigned int abs_num;

					if (num < 0)
						abs_num = (unsigned int)(-num);
					else
						abs_num = (unsigned int)num;

					len = value_len_precision(abs_num, 10,
						has_precision ? precision : -1);

					if (num < 0 || plus_flag || space_flag)
						total_len = len + 1;
					else
						total_len = len;

					count += print_padding(width, total_len, &buffer);

					if (num < 0)
						count += _putchar_buffer(&buffer, '-');
					else if (plus_flag)
						count += _putchar_buffer(&buffer, '+');
					else if (space_flag)
						count += _putchar_buffer(&buffer, ' ');

					count += print_value_precision(abs_num, 10,
						"0123456789",
						has_precision ? precision : -1, &buffer);
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

					len = value_len_precision(num, 10,
						has_precision ? precision : -1);
					count += print_padding(width, len, &buffer);
					count += print_value_precision(num, 10,
						"0123456789",
						has_precision ? precision : -1, &buffer);
					break;
				}
				case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);

					len = value_len_precision(num, 8,
						has_precision ? precision : -1);
					prefix_len = 0;

					if (hash_flag && num != 0 &&
						(!has_precision || precision <= base_len(num, 8)))
						prefix_len = 1;

					count += print_padding(width, len + prefix_len, &buffer);

					if (prefix_len)
						count += _putchar_buffer(&buffer, '0');

					count += print_value_precision(num, 8,
						"01234567",
						has_precision ? precision : -1, &buffer);
					break;
				}
				case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);

					len = value_len_precision(num, 16,
						has_precision ? precision : -1);
					prefix_len = (hash_flag && num != 0) ? 2 : 0;

					count += print_padding(width, len + prefix_len, &buffer);

					if (prefix_len)
					{
						count += _putchar_buffer(&buffer, '0');
						count += _putchar_buffer(&buffer, 'x');
					}

					count += print_value_precision(num, 16,
						"0123456789abcdef",
						has_precision ? precision : -1, &buffer);
					break;
				}
				case 'X':
				{
					unsigned int num = va_arg(args, unsigned int);

					len = value_len_precision(num, 16,
						has_precision ? precision : -1);
					prefix_len = (hash_flag && num != 0) ? 2 : 0;

					count += print_padding(width, len + prefix_len, &buffer);

					if (prefix_len)
					{
						count += _putchar_buffer(&buffer, '0');
						count += _putchar_buffer(&buffer, 'X');
					}

					count += print_value_precision(num, 16,
						"0123456789ABCDEF",
						has_precision ? precision : -1, &buffer);
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
					if (width > 0)
						count += print_num(width, &buffer);
					if (has_precision)
					{
						count += _putchar_buffer(&buffer, '.');
						count += print_num(precision, &buffer);
					}
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
