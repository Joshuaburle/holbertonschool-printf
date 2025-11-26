#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _print_char (va_list *arg);
int _print_str(va_list *arg);
int _print_percentage (va_list *arg);
int _putchar(char c);
/**
 * incomming missing prototypes of functions to complete _printf
 */

typedef struct _printer
{
	char type;
	int (*func)(va_list *);
} printer;

#endif
