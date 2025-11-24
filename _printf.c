#include "main.h"

int printf(const char *format, ...)
{
	va_list arg;
	int i = 0, j, len;
	printer array_of_format_types[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percentage_or_unknown},
		{'\0', NULL}
    };
	va_start(arg, format);

	while(format != NULL && format[i] != '\0')
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
					array_of_format_types[j].func(arg);
					i += 2;
				}
				j++;
			}
			if (j == 3)
			{
				array_of_format_types[2].func(arg);
				i += 2;
			}
		}
	}
	len = i;
	_putchar(\n);
	return (len);
}
