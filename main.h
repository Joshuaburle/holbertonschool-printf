#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _print_char(va_list *arg, char next_char);
int _print_str(va_list *arg, char next_char);
int _print_percentage_or_unknown(va_list *arg, char next_char);
int _print_int(va_list *arg, char next_char);
int _print_recursive_number(int num);
int _putchar(char c);

/**
 * struct _printer - Associates a format specifier with a function.
 * @type: The format specifier character ('c', 's', '%').
 * @func: Pointer to the function that handles printing this type.
 *
 * Description: Used by _printf to map format specifiers in the format
 * string to the corresponding function that prints the argument.
 * Each function must have the signature: int func(va_list *, char next_char);
 */

typedef struct _printer
{
	char type;
	int (*func)(va_list *, char);
} printer;

#endif
