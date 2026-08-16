#include "main.h"
/**
 * get_print_func - Finds the function for a format specifier
 * @specifier: Format specifier to find
 *
 * Return: Pointer to matching function, or NULL
 */
int (*get_print_func(char specifier))(va_list)
{
	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (formats[i].specifier != '\0')
	{
		if (formats[i].specifier == specifier)
			return (formats[i].func);
		i++;
	}

	return (NULL);
}