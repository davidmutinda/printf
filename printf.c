#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _printf - A function that prints inuts to the std output
 * @format: Format by which to print the characters passed to function
 * @...: Multiple function parameters
 *
 * Return: Integer value
 */

int _printf(const char *format, ...)
{
	int i = 0, num = 0;
	va_list ap;

	if (format == NULL)
		exit(0);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			num += switch_statement(format, i, ap);
		}

		else
			_putchar(format[i]);
		i++;
	}
	num += i;
	va_end(ap);
	return (num);
}
