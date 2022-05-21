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
/**
 * print_id - print numbers in base 10 (integers)
 * @a: element of va_list type
 * @s: buffer
 * @index: position on buffer
 * Return: number of "characters" of element called
 */
int print_id(va_list a, char *s, int *index)
{
	unsigned int j, cont = 1;
	unsigned int var1, num, var2, var3 = 1;
	int x, y = 0;

	x = va_arg(a, int);
	var2 = x;

	if (x < 0)
	{
		buffer(s, '-', index);
		var2 = x * (-1);
		y++;
	}
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		cont++;
		var3 = var3 * 10;
	}
	for (j = 1; j <= cont; j++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		y++;
		buffer(s, ('0' + var1), index);
	}
	return (y);
}
