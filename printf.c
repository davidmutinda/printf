#include "main.h"
#include <stdarg.h>

/**
 * _printf - A function that prints inuts to the std output
 * @format: Format by which to print the characters passed to function
 * @...: Multiple function parameters
 *
 * Return: Integer value
 */

int _printf(const char *format, ...)
{
	int i;

	i = 0;

	while (format[i] != '\0')
	{
		_putchar(format[i]);
		i++;
	}
	return (i);
}
