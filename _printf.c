#include <stdarg.h>
#include "main.h"

/**
  * _printf - to print specifiers
  *@format: specifier to be printed
  *Return: format
  */

int _printf(const char *format, ...)
{
	int i = 0, digit, num;
	char ch;
	const char *str;
	va_list args;

	va_start(args, format);

	while (format[i] && format[i] != '\0')
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
	va_end(args);
}
