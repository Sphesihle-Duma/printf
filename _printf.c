#include <stdarg.h>
#include "main.h"
/**
 * print_char - prints a character
 * @valist: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list valist)
{
	char c = va_arg(valist, int);

	_putchar(c);
	return (1);
}
/**
 * print_string - prints a string
 * @valist: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list valist)
{
	char *str = va_arg(valist, char *);
	int len = 0;

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}
/**
 * print_percent - prints a percent sign
 * @valist: argument list
 *
 * Return: number of characters printed
 */
int print_percent(va_list valist)
{
	(void)valist;
	_putchar('%');
	return (1);
}
/**
 * print_int - prints an integer
 * @valist: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list valist)
{
	int n = va_arg(valist, int), div = 1, len = 0;

	if (n < 0)
	{
		_putchar('-');
		len++;
		n *= -1;
	}

	while (n / div > 9)
		div *= 10;

	while (div != 0)
	{
		_putchar((n / div) % 10 + '0');
		div /= 10;
		len++;
	}
	return (len);
}
/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0, len = 0;

	va_start(valist, format);

	if (!format)
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
			case 'c':
				len += print_char(valist);
				break;
			case 's':
				len += print_string(valist);
				break;
			case '%':
				len += print_percent(valist);
				break;
			case 'd':
			case 'i':
				len += print_int(valist);
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				len += 2;
				break;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}

	va_end(valist);

	return (len);
}

