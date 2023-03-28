<<<<<<< HEAD
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
=======
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> parent of 4c9c63a... deleted _printf.c
}

