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

	int number;
	int div;
	int digit;

	i = 0;
	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		/* Handles % at the end of the string */
		/* %c, %d etc - if there is no c after the % it return -1 because there's a incomplete specifier */
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		/* Handle %% Both Tyren & Albert */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			count++;
			i++;
		}
		
		/* Handle %c - Alberts code*/
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			count++;
			i++;
		}
		/* Handle %s - Tyrens code*/
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
		/* Handle %d - Alberts code*/
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			number = va_arg(args, int);

			/*
			If the number is negative, print its minus sign, count (count++) that character, 
			then turn the number positive. The "-" has already been sent to the screen. 
			It doesn't get attached to the number later. It is simply sitting there as the first character that was printed
			The "-" is the very first character since we explicitly send to write().
			*/
			if (number < 0)
			{
				write(1, "-", 1);
				count++;
				number = number * -1;
			/*
			How the loop works for negative value:
			1. check value if it's negative:
				-762534
			2. If yes then Print: 
				"-"
			3. Change value to negative value to postive:
				-762534 -> 762534
			4. The rest of our digit-printing code can handle the digits normally - Print digits:
				7 -> 6 -> 2 -> 5 -> 3 -> 4 
			5. Final output:
				-762534
			*/

			}

			if (number == 0)
			{
				write(1, "0", 1);
				count++;
			} 
			else 
			{
				
				/*Find the first digit*/
				div =  1;

				while(number / div >= 10) /*Keep looping while number / div is 10 or greater*/

					div = div * 10;
					
				/* Print each digit */				
				while (div > 0)
				{
					digit = ((number / div) % 10) + '0'; // Reduce n to the remaining digits

					write(1, &digit, 1); /* */
					count++; /**/
					div = div / 10; // Move the divisor one decimal place to the right
					
				}
			}
			i++;
		}

		/* Handle normal text - Both Tyren & Albert */
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