#include <stdarg.h>
#include "main.h"

/**
  * check_specifier - to check specifiers
  *@format: specifier to be checked
  *@args: variadic args
  *Return: void
  */


void check_specifier(const char *format, va_list args)
{
	int i = 0;
	char ch;
	const char *str;

	while (*format)
	{
		if (i == 0)
		{
			if (*format == '%')
				i = 1;
			else
				_putchar(format[i]);
		}
		else if (i == 1)
		{
			switch (*format)
			{
			case 'c':
				ch = va_arg(args, int);

				_putchar(ch);
				break;
			case 's':
				str = va_arg(args, const char *);

				while (*str)
					_putchar(*str++);
				break;
			}
			i = 0;
		}
		format++;
	}
}

/**
  * _printf - to print
  * @format: specifier(s) to be printed
  * Return: format
  */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	check_specifier(format, args);

	va_end(args);
}
