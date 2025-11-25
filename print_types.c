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
/**
 * Joshua
 */
}

void _print_percentage_or_unknown (va_list *arg)
{
	if (va_arg(*arg, int) == '%')
	{
		_putchar('%');
	}
	else
	{
		char unknown = va_arg(*arg, int);
		_putchar('%');
		_putchar(unknown);
	}
}
