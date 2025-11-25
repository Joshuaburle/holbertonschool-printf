#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
/**
 * incomming missing prototypes of functions to complete _printf
 */

typedef struct _printer
{
	char type;
	void (*func)(va_list *);
} printer;

#endif