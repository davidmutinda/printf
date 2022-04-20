#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stddef.h>
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
 * switch_statement - entry point
 * @format: string
 * @i: integer for iteration
 * @ap: argument pointer
 * Return: void
 */
int switch_statement(const char *format, int i, va_list ap)
{
	char *p, *dec, *integs;
	char charc;
	int num, decimal, integer;

	switch (format[i])
	{
		case 'c':
			charc = va_arg(ap, int);
			num = 1;
			_putchar(charc);
			break;
		case 's':
			p = va_arg(ap, char*);
			if (p == NULL)
				p = "(null)";
			print_string(p);
			num = strlen(p) - 2;
			break;
		case 'i':
			integer = va_arg(ap, int);
			integs = itoa(integer);
			num = strlen(integs) - 2;
			print_numbers(integs); /* function to print number (to be written) */
			break;
		case 'd':
			decimal = va_arg(ap, int);
			dec = itoa(decimal);
			num = strlen(dec) - 2;
			print_numbers(dec); /* function to print number (to be written) */
			break;
		case '%':
			_putchar('%');
			num = -1;
			break;
		default:
			if (format[i] == '\0')
				exit(0);
			_putchar('%');
			_putchar(format[i]);
			break;
	}
	return (num);

}
