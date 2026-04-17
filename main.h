#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct buffer_s - stores buffered output data
 * @output: array used to store output characters
 * @index: current position in the output buffer
 */
struct buffer_s
{
	char output[1024];
	int index;
};

typedef struct buffer_s buffer_t;

int _printf(const char *format, ...);
int _putchar_buffer(buffer_t *buffer, char c);
void flush_buffer(buffer_t *buffer);
int pString(char *string, buffer_t *buffer);
int print_num(int n, buffer_t *buffer);
int print_unsigned(unsigned int n, buffer_t *buffer);
int print_binary(unsigned int n, buffer_t *buffer);
int print_octal(unsigned int n, buffer_t *buffer);
int print_hex_lower(unsigned int n, buffer_t *buffer);
int print_hex_upper(unsigned int n, buffer_t *buffer);
int print_string_custom(char *string, buffer_t *buffer);
int print_pointer(void *ptr, buffer_t *buffer);
int print_num_flags(int n, int plus_flag, int space_flag, buffer_t *buffer);
int print_octal_flag(unsigned int n, int hash_flag, buffer_t *buffer);
int print_hex_lower_flag(unsigned int n, int hash_flag, buffer_t *buffer);
int print_hex_upper_flag(unsigned int n, int hash_flag, buffer_t *buffer);

#endif
