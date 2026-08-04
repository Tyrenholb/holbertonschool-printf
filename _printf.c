#include <stdio.h>
#include "main.h"
#include <unistd.h>


int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			i += 2;
			count++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}

	return (count);
}
