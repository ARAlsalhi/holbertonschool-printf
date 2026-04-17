#include "main.h"

/**
 
*_printf - produces output according to a format
*@format: string containing the format*
*Return: number of characters printed*/
int _printf(const char format, ...)
{
    va_list args;
    int count = 0;
    buffer_t buffer;

    buffer.index = 0;

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (format != '\0')
    {
        if (format == '%')
        {
            format++;

            if (format == '\0')
            {
                va_end(args);
                return (-1);
            }

            switch (format)
            {
                case 'c':
                    count += _putchar_buffer(&buffer, va_arg(args, int));
                    break;
                case 's':
                    count += pString(va_arg(args, char), &buffer);
                    break;
                case 'S':
                    count += print_string_custom(va_arg(args, char ), &buffer);
                    break;
                case 'd':
                case 'i':
                    count += print_num(va_arg(args, int), &buffer);
                    break;
                case '%':
                    count += _putchar_buffer(&buffer, '%');
                    break;
                case 'b':
                    count += print_binary(va_arg(args, unsigned int), &buffer);
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int), &buffer);
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int), &buffer);
                    break;
                case 'x':
                    count += print_hex_lower(va_arg(args, unsigned int), &buffer);
                    break;
                case 'X':
                    count += print_hex_upper(va_arg(args, unsigned int), &buffer);
                    break;
                default:
                    count += _putchar_buffer(&buffer, '%');
                    count += _putchar_buffer(&buffer,format);
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
