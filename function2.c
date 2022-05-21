#include "main.h"
/**
 * switch_h - select to print the hexa char
 * @sum: num to analyze
 * @h: array
 * @y: spaces of the array
 * Return: number of "characters" of element called
 */
int switch_h(int sum, int *h, int y)
{
	switch (sum)
		{
		case 10:
			h[y] = 'a';
			break;
		case 11:
			h[y] = 'b';
			break;
		case 12:
			h[y] = 'c';
			break;
		case 13:
			h[y] = 'd';
			break;
		case 14:
			h[y] = 'e';
			break;
		case 15:
			h[y] = 'f';
			break;
		default:
			h[y] = sum;
		}
	return (h[y]);
}
/**
 * impresion_x - print hexadecimal lowercase
 * @a: the array to be analized
 * @b: size of array
 * @s: buffer
 * @index: position on buffer
 * Return: number of "characters" of element called
 */
int impresion_x(int *a, int b, char *s, int *index)
{
	int c = 0, y = 0, mul = 1;
	int sum = 0, i, j;
	int h[8] = {0};

	while (c < b)
	{
		sum = 0;
		for (i = 0; i < 4; i++)
		{
			if (i == 0 && c < b)
			{
				sum = sum + a[c];
				mul = 2;
				c++; }
			else if (i != 0 && c < b)
			{
				sum = sum + (mul * a[c]);
				c++;
				mul = 2 * mul; }
			else
				break;
		}
		h[y] = switch_h(sum, h, y);
		y++;
	}
	for (j = y - 1; j >= 0; j--)
	{
		if (h[j] == 'a' || h[j] == 'b' || h[j] == 'c' || h[j] == 'd'
			|| h[j] == 'e' || h[j] == 'f')
			buffer(s, h[j], index);
		else
			buffer(s, (h[j] + '0'), index);
	}
		return (y);
}
/**
 * print_x - print the hexadecimal number in base 16
 * @a: element of va_list type
 * @s: buffer
 * @index: position on buffer
 * Return: number of "characters" of element called
 */
int print_x(va_list a, char *s, int *index)
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
		y = impresion_x(arr, c, s, index);
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
		y = impresion_x(arr, 32, s, index);
	}
	return (y);
}
