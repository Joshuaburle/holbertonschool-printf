#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

void _print_char (va_list *arg)
{
	char letter = va_arg(*arg, int);
	_putchar(letter);
}

void _print_str (va_list *arg)
{
	int i = 0;
	char *str = va_arg(*arg, char *);

	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			_putchar (str[i]);
			i++;
		}
	}
}

void _print_percentage (va_list *arg)
{
	(void)arg;
	_putchar('%');
}
