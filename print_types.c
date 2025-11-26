#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int _print_char (va_list *arg)
{
	char letter = va_arg(*arg, int);
	_putchar(letter);
	return (1);
}

int _print_str (va_list *arg)
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
	return (i);
}

int _print_percentage (va_list *arg)
{
	(void)arg;
	_putchar('%');
	return (1);
}
