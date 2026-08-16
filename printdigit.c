#include "main.h"
/**
 * print_number - Prints an integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
	long number;
	long divisor;
	char digit;
	int count;

	number = va_arg(args, int);
	count = 0;

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		count++;
	}

	divisor = 1;
	while (number / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		digit = ((number / divisor) % 10) + '0';
		write(1, &digit, 1);
		count++;
		divisor /= 10;
	}

	return (count);
}