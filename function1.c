#include "main.h"
/**
 * impresion_o - print the octal number
 * @a: array to be analized
 * @b: size of array
 * @s: buffer
 * @index:position on buffer
 * Return: number of "characters" of element called
 */
int impresion_o(int *a, int b, char *s, int *index)
{
	int c = 0, y = 0;
	int sum = 0, i, j;
	int octal[11] = {0};

	while (c < b)
	{
		sum = 0;
		for (i = 0; i < 3; i++)
		{
			if (i == 0 && c < b)
			{
				sum = sum + a[c];
				c++;
			}
			else if (i != 0 && c < b)
			{
				sum = sum + (2 * i * a[c]);
				c++;
			}
			else
				break;
		}
		octal[y] = sum;
		y++;
	}
	for (j = y - 1; j >= 0; j--)
		buffer(s, (octal[j] + '0'), index);
	return (y);
}
/**
 * print_u - print unsigned decimal
 * @a: element of va_list type
 * @s: buffer
 * @index:position on buffer
 * Return: number of "characters" of element called
 */
int print_u(va_list a, char *s, int *index)
{
	int x;
	unsigned int u;
	unsigned int j, cont = 1;
	unsigned int var1, num, var2, var3 = 1;
	int  y = 0;

	x = (va_arg(a, int));

	u = x;
	var2 = u;
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
/**
 * print_o - print octal number in base 8
 * @a: element of va_list type
 * @s: buffer
 * @index:position on buffer
 * Return: number of "characters" of element called
 */
int print_o(va_list a, char *s, int *index)
{
	int x, c, d, y = 0, aux = 0;
	int arr[32] = {0};

	aux = va_arg(a, int);
	x = aux;/* The original decimal number*/
	if (aux == 0)
	{
		buffer(s, '0', index);
		return (1);
	}
	if (aux < 0)
		x = -(x + 1);/*Add 1 to obtain two's complement*/
	for (c = 0; x > 0; c++)/*Divide the number by 2 and store in the array*/
	{
		arr[c] = x % 2;
		x = x / 2;
	}
	if (aux >= 0)
	{
		y = impresion_o(arr, c, s, index);
	}
	else
	{
		for (d = 31; d >= 0; d--)/*Finds the one's complement for the number*/
		{
			if (arr[d] == 1)
				arr[d] = 0;
			else if (arr[d] == 0)
				arr[d] = 1;
		}
		y = impresion_o(arr, 32, s, index);
	}
	return (y);
}
/**
 * print_2X - prints 2 digits hex
 * @a: element of va_list type
 * @s: buffer
 * @index:position on buffer
 * Return: number of "characters" of element called
 */
int print_2X(int a, char *s, int *index)
{
	int temp, a3[2] = {0};
	int i = 0, j;

	for (; i < 2; i++)
	{
		temp = a % 16;
		if (temp >= 10)
		{
			a3[i] = switch_H(temp, a3, i);
		}
		else
		{
			a3[i] = temp;
		}
		a = a / 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (a3[j] == 'A' || a3[j] == 'B' || a3[j] == 'C' || a3[j] == 'D'
			|| a3[j] == 'E' || a3[j] == 'F')
			buffer(s, a3[j], index);
		else
			buffer(s, (a3[j] + '0'), index);
	}
	return (2);
}
/**
 * print_S - print an alternative to a non printable char
 * @a: element of va_list type
 * @s: buffer
 * @index:position on buffer
 * Return: number of "characters" of element called
 */
int print_S(va_list a, char *s, int *index)
{
	int i;
	int c = 0;
	char *str = va_arg(a, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer(s, '\\', index);
			buffer(s, 'x', index);
			c += 2;
			c += print_2X((str[i]), s, index);
		}
		else
		{
			buffer(s, str[i], index);
			c++;
		}
	}
	return (c);
}
