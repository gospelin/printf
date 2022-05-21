#include "main.h"
#include <stdlib.h>

/**
  * print_c - prints a char
  * @c: character to be prunted
  */

void print_c(va_list c)
{
	char ch = va_arg(c, int);

	_putchar(ch);
}

/**
 * print_s - prints a string
 * @s: string to print
 */

void print_s(va_list s)
{
	const char *str = va_arg(s, const char *);

	while (*str)
		putchar(*str++);
}
