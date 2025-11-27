#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _print_char - A function printing a uniq char.
 * @arg: The char to print.
 * @next_char: the letter used after '%'
 *
 * Description: _print_char prints a char. It is a function created for _printf
 *
 * Return: it returns 1 for the lenght of a single char.
 */

int _print_char (va_list *arg, char next_char)
{
	char letter;
	(void)next_char;

	letter = va_arg(*arg, int);
	_putchar(letter);
	return (1);
}

/**
 * _print_str - A function printing a string.
 * @arg: The string to print.
 * @next_char: the letter used after '%'
 *
 * Description: _print_str prints a string. It's a function created for _printf
 *
 * Return: it returns the lenght of the string.
 */

int _print_str(va_list *arg, char next_char)
{
	int i = 0;
	char *str = va_arg(*arg, char *);
	(void)next_char;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		_putchar (str[i]);
		i++;
	}
	return (i);
}

/**
 * _print_percentage_or_unknown - A function printing % or unknown char.
 * @arg: There is no variadic argument given for this function so it's void.
 * @next_char: the letter used after '%'
 *
 * Description: this function manage if the next char is null
 * or prints it if it's not null
 *
 * Return: it returns 1 or 2 depending on the lenght.
 */

int _print_percentage_or_unknown(va_list *arg, char next_char)
{
	(void)arg;
	if (next_char == '\0')
		return (0);
	else if (next_char == '%')
	{
		_putchar('%');
		return (1);
	}
	else
	{
		_putchar('%');
		_putchar(next_char);
		return (2);
	}
}
