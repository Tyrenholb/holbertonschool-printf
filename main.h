#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * struct format_handler - Matches a specifier to a print function
 * @specifier: Conversion specifier
 * @func: Function used to print the argument
 *
 * Description: Stores a format character and its matching function.
 */
typedef struct format_handler
{
	char specifier;
	int (*func)(va_list);
} format_t;

int _printf(const char *format, ...);
int (*get_print_func(char specifier))(va_list);

int print_char(va_list args);
int print_string(va_list args);
int print_number(va_list args);
int print_percent(va_list args);

int _putchar(char c);

#endif