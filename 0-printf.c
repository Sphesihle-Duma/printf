#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - returns the number characters printed
 * @format: string to be printed
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        int num_of_characters = 0;
        va_list arg_container;
        char *str;
        char c;

        va_start(arg_container, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
        while (*format != '\0')
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case '%':
                                        _putchar(*format);
                                        num_of_characters++;
                                        break;
                                case 'c':
                                        c = va_arg(arg_container, int);
                                        _putchar(c);
                                        num_of_characters++;
                                        break;
                                case 's':
                                        str = va_arg(arg_container, char *);
                                        while (*str)
                                        {
                                                _putchar(*str++);
                                                num_of_characters++;
                                        }
                                        break;
                                default:
                                        _putchar('%');
                                        _putchar(*format);
                                        num_of_characters+= 2;
                                        break;
                        }
                }
                else
                {
                        _putchar(*format);
                        num_of_characters++;
                }
                format++;
        }
        va_end(arg_container);
        return (num_of_characters);
}

