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
	int i = 0, j, len, found = 0;
	printer array_of_format_types[] = {
		{'c', _print_char}, {'s', _print_str}, {'%', _print_percentage},
		{'\0', NULL} };
	va_start(arg, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
		}
		else
		{
			j = 0;
			while (array_of_format_types[j].type != '\0')
			{
				if (format[i + 1] == array_of_format_types[j].type)
				{
					array_of_format_types[j].func(&arg);
					found = 1;
					break;
				}
				j++;
			}
			if (!found)
			{
				_putchar('%');
				_putchar(format[i + 1]);
			}
			i+=2;
		}
	}
	va_end(arg);
	len = i;
	return (len);
}
