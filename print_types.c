#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
 * _print_str - Prints a string.
 * @arg: Pointer to the variadic argument list.
 * @next_char: The format specifier character (after '%'), unused here.
 *
 * Description: Extracts a string from the variadic arguments and prints it.
 * If the string is NULL, prints "(null)" instead.
 *
 * Return: Returns the length of the printed string.
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
 * _print_percentage_or_unknown - Prints '%' or an unknown format.
 * @arg: Not used.
 * @next_char: The character after '%'.
 *
 * Description: If the next character is '%', prints '%'.
 * Otherwise, prints '%' followed by the unknown character.
 *
 * Return: 1 if only '%' was printed, 2 if '%'
 * and an unknown character were printed,
 * 0 if next_char is '\0'.
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

/**
 * _print_recursive_number - Prints an integer recursively.
 * @num: The non-negative integer to print.
 *
 * Description: Recursively prints each digit of num
 * from most significant to least.
 *
 * Return: Returns the number of characters printed.
 */

int _print_recursive_number(int num)
{
	int len = 0;

	if (num >= 10)
		len += _print_recursive_number(num / 10);
	_putchar(num % 10 + '0');
	len++;
	return (len);
}

/**
 * _print_int - Prints a signed integer.
 * @arg: Pointer to the variadic argument list.
 * @next_char: The format specifier character (after '%'), unused here.
 *
 * Description: Extracts an integer from the variadic arguments and prints it.
 * Handles negative numbers, including INT_MIN.
 *
 * Return: Returns the total number of characters printed.
 */

int _print_int(va_list *arg, char next_char)
{
	int number, len = 0;
	(void)next_char;

	number = va_arg(*arg, int);
	if (number < 0)
	{
		_putchar('-');
		len = 1;
		if (number == INT_MIN)
		{
			write(1, "2147483648", 10);
			return (len += 10);
		}
		number = -number;
	}
	len += _print_recursive_number(number);
	return (len);
}
