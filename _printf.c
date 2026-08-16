#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*func)(va_list);
	int i;
	int count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			count += write(1, &format[i], 1);
		else
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			i++;
			func = get_print_func(format[i]);
			if (func != NULL)
				count += func(args);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}