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
	int plus_flag, space_flag, hash_flag, zero_flag, minus_flag;
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
			zero_flag = 0;
			minus_flag = 0;
			width = 0;
			precision = 0;
			has_precision = 0;
			length_mod = '\0';

			while (*format == '+' || *format == ' ' || *format == '#' ||
				*format == '0' || *format == '-')
			{
				if (*format == '+')
					plus_flag = 1;
				else if (*format == ' ')
					space_flag = 1;
				else if (*format == '#')
					hash_flag = 1;
				else if (*format == '0')
					zero_flag = 1;
				else if (*format == '-')
					minus_flag = 1;
				format++;
			}

			if (*format == '*')
			{
				width = va_arg(args, int);
				if (width < 0)
				{
					minus_flag = 1;
					width = -width;
				}
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

			if (minus_flag)
				zero_flag = 0;

			switch (*format)
			{
				case 'c':
				{
					int len_c = 1;
					int ch = va_arg(args, int);

					if (!minus_flag)
						count += print_padding(width, len_c, &buffer);
					count += _putchar_buffer(&buffer, ch);
					if (minus_flag)
						count += print_padding(width, len_c, &buffer);
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					int len_s = string_len(str);

					if (has_precision && precision < len_s)
						len_s = precision;

					if (!minus_flag)
						count += print_padding(width, len_s, &buffer);
					count += print_string_precision(str,
						has_precision ? precision : -1, &buffer);
					if (minus_flag)
						count += print_padding(width, len_s, &buffer);
					break;
				}
				case 'S':
					count += print_string_custom(va_arg(args, char *), &buffer);
					break;
				case 'r':
					count += print_reverse(va_arg(args, char *), &buffer);
					break;
				case 'R':
					count += print_rot13(va_arg(args, char *), &buffer);
					break;
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					unsigned int abs_num;
					char sign_char = '\0';

					if (num < 0)
					{
						sign_char = '-';
						abs_num = (unsigned int)(-(long int)num);
					}
					else
					{
						abs_num = (unsigned int)num;
						if (plus_flag)
							sign_char = '+';
						else if (space_flag)
							sign_char = ' ';
					}

					len = value_len_precision(abs_num, 10,
						has_precision ? precision : -1);
					prefix_len = (sign_char != '\0') ? 1 : 0;
					total_len = len + prefix_len;

					if (!minus_flag)
					{
						if (zero_flag && !has_precision)
						{
							if (sign_char != '\0')
								count += _putchar_buffer(&buffer, sign_char);
							count += print_zero_padding(width,
								total_len, &buffer);
							count += print_value_precision(abs_num, 10,
								"0123456789",
								has_precision ? precision : -1, &buffer);
						}
						else
						{
							count += print_padding(width, total_len, &buffer);
							if (sign_char != '\0')
								count += _putchar_buffer(&buffer, sign_char);
							count += print_value_precision(abs_num, 10,
								"0123456789",
								has_precision ? precision : -1, &buffer);
						}
					}
					else
					{
						if (sign_char != '\0')
							count += _putchar_buffer(&buffer, sign_char);
						count += print_value_precision(abs_num, 10,
							"0123456789",
							has_precision ? precision : -1, &buffer);
						count += print_padding(width, total_len, &buffer);
					}
					break;
				}
				case '%':
				{
					int len_p = 1;

					if (!minus_flag)
					{
						if (zero_flag)
							count += print_zero_padding(width, len_p, &buffer);
						else
							count += print_padding(width, len_p, &buffer);
					}
					count += _putchar_buffer(&buffer, '%');
					if (minus_flag)
						count += print_padding(width, len_p, &buffer);
					break;
				}
				case 'b':
					count += print_binary(va_arg(args, unsigned int), &buffer);
					break;
				case 'u':
				{
					unsigned int num_u = va_arg(args, unsigned int);

					len = value_len_precision(num_u, 10,
						has_precision ? precision : -1);

					if (!minus_flag)
					{
						if (zero_flag && !has_precision)
							count += print_zero_padding(width, len, &buffer);
						else
							count += print_padding(width, len, &buffer);
					}
					count += print_value_precision(num_u, 10,
						"0123456789",
						has_precision ? precision : -1, &buffer);
					if (minus_flag)
						count += print_padding(width, len, &buffer);
					break;
				}
				case 'o':
				{
					unsigned int num_o = va_arg(args, unsigned int);
					int raw_len;

					len = value_len_precision(num_o, 8,
						has_precision ? precision : -1);
					raw_len = base_len(num_o, 8);
					prefix_len = 0;

					if (hash_flag && num_o != 0 &&
						(!has_precision || precision <= raw_len))
						prefix_len = 1;

					total_len = len + prefix_len;

					if (!minus_flag)
					{
						if (zero_flag && !has_precision)
						{
							if (prefix_len)
								count += _putchar_buffer(&buffer, '0');
							count += print_zero_padding(width,
								total_len, &buffer);
							count += print_value_precision(num_o, 8,
								"01234567",
								has_precision ? precision : -1, &buffer);
						}
						else
						{
							count += print_padding(width, total_len, &buffer);
							if (prefix_len)
								count += _putchar_buffer(&buffer, '0');
							count += print_value_precision(num_o, 8,
								"01234567",
								has_precision ? precision : -1, &buffer);
						}
					}
					else
					{
						if (prefix_len)
							count += _putchar_buffer(&buffer, '0');
						count += print_value_precision(num_o, 8,
							"01234567",
							has_precision ? precision : -1, &buffer);
						count += print_padding(width, total_len, &buffer);
					}
					break;
				}
				case 'x':
				{
					unsigned int num_x = va_arg(args, unsigned int);

					len = value_len_precision(num_x, 16,
						has_precision ? precision : -1);
					prefix_len = (hash_flag && num_x != 0) ? 2 : 0;
					total_len = len + prefix_len;

					if (!minus_flag)
					{
						if (zero_flag && !has_precision)
						{
							if (prefix_len)
							{
								count += _putchar_buffer(&buffer, '0');
								count += _putchar_buffer(&buffer, 'x');
							}
							count += print_zero_padding(width,
								total_len, &buffer);
							count += print_value_precision(num_x, 16,
								"0123456789abcdef",
								has_precision ? precision : -1, &buffer);
						}
						else
						{
							count += print_padding(width, total_len, &buffer);
							if (prefix_len)
							{
								count += _putchar_buffer(&buffer, '0');
								count += _putchar_buffer(&buffer, 'x');
							}
							count += print_value_precision(num_x, 16,
								"0123456789abcdef",
								has_precision ? precision : -1, &buffer);
						}
					}
					else
					{
						if (prefix_len)
						{
							count += _putchar_buffer(&buffer, '0');
							count += _putchar_buffer(&buffer, 'x');
						}
						count += print_value_precision(num_x, 16,
							"0123456789abcdef",
							has_precision ? precision : -1, &buffer);
						count += print_padding(width, total_len, &buffer);
					}
					break;
				}
				case 'X':
				{
					unsigned int num_xu = va_arg(args, unsigned int);

					len = value_len_precision(num_xu, 16,
						has_precision ? precision : -1);
					prefix_len = (hash_flag && num_xu != 0) ? 2 : 0;
					total_len = len + prefix_len;

					if (!minus_flag)
					{
						if (zero_flag && !has_precision)
						{
							if (prefix_len)
							{
								count += _putchar_buffer(&buffer, '0');
								count += _putchar_buffer(&buffer, 'X');
							}
							count += print_zero_padding(width,
								total_len, &buffer);
							count += print_value_precision(num_xu, 16,
								"0123456789ABCDEF",
								has_precision ? precision : -1, &buffer);
						}
						else
						{
							count += print_padding(width, total_len, &buffer);
							if (prefix_len)
							{
								count += _putchar_buffer(&buffer, '0');
								count += _putchar_buffer(&buffer, 'X');
							}
							count += print_value_precision(num_xu, 16,
								"0123456789ABCDEF",
								has_precision ? precision : -1, &buffer);
						}
					}
					else
					{
						if (prefix_len)
						{
							count += _putchar_buffer(&buffer, '0');
							count += _putchar_buffer(&buffer, 'X');
						}
						count += print_value_precision(num_xu, 16,
							"0123456789ABCDEF",
							has_precision ? precision : -1, &buffer);
						count += print_padding(width, total_len, &buffer);
					}
					break;
				}
				case 'p':
				{
					int ptr_len = 0;
					void *ptr = va_arg(args, void *);

					if (ptr == NULL)
						ptr_len = 5;
					else
						ptr_len = 2 + base_len((unsigned int)
							(unsigned long int)ptr, 16);

					if (!minus_flag)
						count += print_padding(width, ptr_len, &buffer);
					count += print_pointer(ptr, &buffer);
					if (minus_flag)
						count += print_padding(width, ptr_len, &buffer);
					break;
				}
				default:
					count += _putchar_buffer(&buffer, '%');
					if (plus_flag)
						count += _putchar_buffer(&buffer, '+');
					if (space_flag)
						count += _putchar_buffer(&buffer, ' ');
					if (hash_flag)
						count += _putchar_buffer(&buffer, '#');
					if (zero_flag)
						count += _putchar_buffer(&buffer, '0');
					if (minus_flag)
						count += _putchar_buffer(&buffer, '-');
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
