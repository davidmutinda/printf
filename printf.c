#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * print_string - prints string
 * @p: string
 * Return: void
 */
void print_string(char *p)
{
	int n;

	n = 0;

	while (p[n] != '\0')
	{
		_putchar(p[n]);
		n++;
	}
}
/**
 * _printf - A function that prints inuts to the std output
 * @format: Format by which to print the characters passed to function
 * @...: Multiple function parameters
 *
 * Return: Integer value
 */

int _printf(const char *format, ...)
{
	int i, num;
	va_list ap;
	char charc;
	char *p;

	va_start(ap, format);
	i = 0;
	num = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					charc = va_arg(ap, int);
					num -= 1;
					_putchar(charc);
					break;

				case 's':
					p = va_arg(ap, char*);
					num = strlen(p);
					num -= 2;
					print_string(p);
					break;

				case '%':
					_putchar('%');
					num -= 1;
					break;

				default:
					break;
			}
			i++;
			continue;
		}
		_putchar(format[i]);
		i++;
	}
	num += (i - 1);
	va_end(ap);
	return (num);
}
