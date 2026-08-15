#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(va_list args);

/**
* struct format - Matches a format specifier with a function
* @specifier: Format specifier
* @func: Function used to print the argument
*/

typedef struct format
{
	char specifier;
	int (*func)(va_list);
} format_t;
#endif