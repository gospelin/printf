#include "main.h"
/**
 * print_R - printRot13
 * @a: num to analyze
 * @s: array
 * @index: place in the array
 * Return: number of "characters" of element called
 */
int print_R(va_list a, char *s, int *index)
{
	int i = 0, j, c;
	char *str = va_arg(a, char *);
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		for (j = 0; j <= 51; j++)
		{
			if (str[i] == arr[j])
			{
				buffer(s, rot[j], index);
				c++;
				break;
			}
		}
		if (!arr[j])
		{
			buffer(s, str[i], index);
			c++;
		}
		i++;
	}
	return (c);
}
/**
 * print_r - print inverse string
 * @a: num to analyze
 * @s: array
 * @index: place in the array
 * Return: number of "characters" of element called
 */
int print_r(va_list a, char *s, int *index)
{
	int i = 0, j;
	char *str, *p, c1, c2;

	str = va_arg(a, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (-1);
	for (j = 0; j < i; j++)
	{
		c1 = str[j];
		c2 = str[(i - 1) - j];
		p[j] = c2;
		p[(i - 1) - j] = c1;
		buffer(s, p[j], index);
	}
	free(p);
	return (i);
}
/**
 * print_p - print adress using binary code
 * @a: num to analyze
 * @s: array
 * @index: place in the array
 * Return: number of "characters" of element called
 */
int print_p(va_list a, char *s, int *index)
{
	void *p1;
	long int tam = 0, var;
	int i, j, z = 0, k = 0;
	char *n = "(nil)", *hex = "0123456789abcdef", arr[16] = "";

	p1 = va_arg(a, void *);
	if (!p1)
	{
		while (n[z] != '\0')
		{
			buffer(s, n[z], index);
			z++;
		}
		return (z);
	}
	tam = (long int) p1;
	buffer(s, '0', index);
	buffer(s, 'x', index);

	for (i = 0; i < (int)(sizeof(void *) * 2); i++)
	{
		var = tam & 0x0F;
		arr[i] = hex[var];
		tam = tam >> 4;
	}
	for (j = i - 1; j >= 0; j--)
	{
		if (arr[j] != '0')
			break;
	}
	for (; j >= 0; j--)
	{
		k++;
		buffer(s, arr[j], index);
	}
	return (k + 2);
}
