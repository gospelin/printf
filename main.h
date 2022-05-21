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

typedef struct a
{
	char c;
	int (*p)(va_list list, char *s, int *index);
} choose;

int _putchar(char c);
int _printf(const char *format, ...);
void buffer(char *s, char x, int *index);
int print_c(va_list a, char *s, int *index);
int print_s(va_list a, char *s, int *index);
int print_por(va_list a, char *s, int *index);
int print_id(va_list a, char *s, int *index);
int print_bin(va_list a, char *s, int *index);
int print_u(va_list a, char *s, int *index);
int print_o(va_list a, char *s, int *index);
int print_x(va_list a, char *s, int *index);
int print_X(va_list a, char *s, int *index);
int print_S(va_list a, char *s, int *index);
int switch_H(int sum, int *h, int y);
int print_R(va_list a, char *s, int *index);
int print_r(va_list a, char *s, int *index);
int print_p(va_list a, char *s, int *index);

#endif /* _MAIN_H_ */
