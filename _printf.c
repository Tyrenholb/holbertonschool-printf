#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i;
	int count;
	char c;
	va_list args;

	i = 0;
	count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{   /* Handle % */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			i ++;
			count++;
		}

		/* Print a character */
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
			c = va_arg(args, int);
            write(1, &c, 1); 
			count++;
			i++;
        }

        /*This handle normal characters*/
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