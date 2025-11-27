#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - A function printing its variadic arguments.
 * @format: The str to print which can contain a format.
 *
 * Description: _printf prints a formatted string. It takes a format string and
 * additional arguments that match the format specifiers inside the string.
 *
 * Return: it returns the lenght of the sentence.
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0, j, len = 0, found = 0;
	printer array_of_format_types[] = { {'c', _print_char}, {'s', _print_str},
		{'%', _print_percentage_or_unknown}, {'\0', NULL} };
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++, len++;
		}
		else
		{
			found = 0;
			if (format[i + 1] == '\0')
			{
				return (0);
			}
			for (j = 0; array_of_format_types[j].type != '\0'; j++)
			{
				if (format[i + 1] == array_of_format_types[j].type)
				{
					len += array_of_format_types[j].func(&arg, format[i + 1]);
					found = 1;
					break;
				}
			}
			if (!found)
				len += _print_percentage_or_unknown(NULL, format[i + 1]);
			i += 2;
		}
	}
	va_end(arg);
	return (len);
}
