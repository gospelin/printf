#include "main.h"

/**
  * print_c - print characters
  * @a: element of va_list type
  * @s: buffer
  * @index: position on buffer
  * Return: number of "characters" of element called
 */
int print_c(va_list a, char *s, int *index)
{
	int x;

	x = va_arg(a, int);
	buffer(s, x, index);
	return (1);
}
/**
 * print_s - print strings
 * @a: element of va_list type
 * @s: buffer
 * @index: position on buffer
 * Return: number of "characters" of element called
 */
int print_s(va_list a, char *s, int *index)
{
	char *x;
	int y = 0;
	int c = 0;

	x = va_arg(a, char *);
	if (!x)
		x = "(null)";
	while (x[c])
	{
		buffer(s, x[c], index);
		c++;
		y++;
	}
	return (y);
}
/**
 * print_por - print character %
 * @a: element of va_list type
 * @s: buffer
 * @index: position on buffer
 * Return: number of "characters" of element called
 */
int print_por(va_list a, char *s, int *index)
{
	(void)a;
	buffer(s, '%', index);
	return (1);
}
