#include "main.h"
#include <stdarg.h>

/**
 * print_char - prints a single character to stdout
 * @c: the character to be printed
 * Return: the number of characters printed
 */
int print_char(char c)
{
        return (_putchar(c));
}

/**
 * print_string - prints a string to stdout
 * @str: the string to be printed
 * Return: the number of characters printed
 */
int print_string(char *str)
{
        int num_of_characters = 0;

        while (*str != '\0')
        {
                _putchar(*str);
                num_of_characters++;
                str++;
        }

        return (num_of_characters);
}

/**
 * print_number - prints a number to stdout
 * @n: the number to be printed
 * Return: the number of characters printed
 */
int print_number(int n)
{
        unsigned int num;
        int num_of_characters = 0;

        if (n < 0)
        {
                _putchar('-');
                num_of_characters++;
                num = -n;
        }
        else
                num = n;

        if (num / 10)
                num_of_characters += print_number(num / 10);

        _putchar(num % 10 + '0');
        num_of_characters++;

        return (num_of_characters);
}

/**
 * _printf - prints a formatted string to stdout
 * @format: the format string to be printed
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
        int num_of_characters = 0;
        va_list arg_container;

        va_start(arg_container, format);

        while (*format != '\0')
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'c':
                                        num_of_characters += print_char(va_arg(arg_container, int));
                                        break;
                                case 's':
                                        num_of_characters += print_string(va_arg(arg_container, char *));
                                        break;
                                case 'd':
                                case 'i':
                                        num_of_characters += print_number(va_arg(arg_container, int));
                                        break;
                                default:
                                        _putchar('%');
                                        _putchar(*format);
                                        num_of_characters += 2;
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

