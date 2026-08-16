#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);

	return (1);
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;

	write(1, "%", 1);

	return (1);
}