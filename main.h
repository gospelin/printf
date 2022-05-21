#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
  * struct print - struct to print data types
  * @t: data type
  * @f: function
  */

typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

int _putchar(char c);
int _printf(const char *format, ...);
static int (*check_specifiers(const char *format))(va_list);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_b(va_list b)


#endif /* _MAIN_H_ */
