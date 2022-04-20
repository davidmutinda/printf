#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * itoa -converts integer to string
 * @k: integer
 * Return: string
 */
int itoa(int k)
{
	int i, j, n = 0, div;

	if (k < 0)
	{
		_putchar('-');
		k *= -1;
		n += 1;
	}
	j = k;
	for (i = 1; j > 9; i *= 10, j /= 10)
		;
	while (i >= 1)
	{
		div = k / i;
		_putchar(div + '0');
		k %= i;
		i /= 10;
		n++;
	}
	return (n);
}
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
	char *p;
	char charc;
	int num, decimal, integer;

	switch (format[i])
	{
		case 'c':
			charc = va_arg(ap, int);
			num = -1;
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
			num = itoa(integer) - 2;
			break;
		case 'd':
			decimal = va_arg(ap, int);
			num = itoa(decimal) - 2;
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
