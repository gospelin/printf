#include "main.h"

/**
 * buffer - defines a local buffer of 1024 chars
 * @s: buffer
 * @x: char to be printed
 * @index: actual position on buffer
 * Return: return a function
 */
void buffer(char *s, char x, int *index)
{
	s[*index] = x;
	*index = *index + 1;
	if (*index == 1024)
	{
		write(1, s, *index);
		*index = 0;
	}
}
/**
 * getfunction - gets the function choose
 * @c: char to find
 * Return: return a function
 */
int (*getfunction(char c))(va_list a, char *s, int *index)
{
	int c1;
	choose l[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_por}, {'i', print_id},
		{'d', print_id}, {'b', print_bin}, {'u', print_u}, {'o', print_o},
		{'x', print_x}, {'X', print_X}, {'S', print_S}, {'R', print_R},
		{'r', print_r}, {'p', print_p}, {'\0', NULL}
	};
	for (c1 = 0; l[c1].c != '\0'; c1++)
	{
		if (c == l[c1].c)
		{
			return (l[c1].p);
		}
	}
	return (NULL);
}
/**
 * _printf - prints depends of the arguments.
 * @format: s for string, c for char, d for decimals, i for integers,
 * b for cast to binary, u for cast to unsigned decimal, o for print
 * in octal, x for lowercase Hexadecimal, X for Uppercase Hexadecimal,
 * p to print adresses
 * Return: new string.
 */
int _printf(const char *format, ...)
{
	int c1 = 0, w = 0, x = -1, (*f)(va_list, char *s, int *m);
	int *index;
	char *s;
	va_list elements;

	va_start(elements, format);
	s = malloc(1024);
	index = &w;
	if (!s)
		return (-1);
	if (format)
	{
		x = 0;
		for (; format[c1] != '\0'; c1++, x++)
		{
			if (format[c1] != '%')
				buffer(s, format[c1], index);
			else if (format[c1] == '%' && format[c1 + 1] == '\0')
			{
				return (-1);
			}
			else if (format[c1] == '%' && format[c1 + 1] != '\0')
			{
				f = getfunction(format[c1 + 1]);
				if (f)
				{
					x = (x + f(elements, s, index)) - 1;
					c1++;
				}
				else
					buffer(s, format[c1], index);
			}
		}
	}
	if (*index != 1024)
		write(1, s, *index);
	free(s);
	va_end(elements);
	return (x);
}
