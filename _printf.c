#include "main.h"

/**
 * _printf - Prints normal text, characters, strings, and percent signs.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */




 format_t formats[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_number},
	{'i', print_number},
	{'%', print_percent},
	{'\0', NULL}
};

int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char c;
	int i;
	int j;
	int count;

	int number;
	int div;
	int digit;

	i = 0;
	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

