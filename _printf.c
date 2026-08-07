#include "main.h"

/**
 * _printf - Prints normal text, characters, strings, and percent signs.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char c;
	int i;
	int j;
	int count;

	i = 0;
	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		/* Handle %% */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			count++;
			i++;
		}
		/* Handle %c */
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			count++;
			i++;
		}
		/* Handle %s */
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, char *);

			if (str == NULL)
				str = "(null)";

			j = 0;

			while (str[j] != '\0')
			{
				write(1, &str[j], 1);
				count++;
				j++;
			}

			i++;
		}
		/* Handle normal text */
		else
		{
			write(1, &format[i], 1);
			count++;
		}

		i++;
	}

	va_end(args);

	return (count);
}