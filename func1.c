#include "main.h"

/**
 * option - a function that choose the correct func
 * @s: the first input
 * @list: the second input
 * Return: int
*/
int option(char s, va_list *list)
{
	int coun = 0;

	if (s == '%')
		coun += kh_mod(s);
	else if (s == 'c')
		coun += kh_chaar(va_arg(*list, int));
	else if (s == 's')
		coun += kh_string(va_arg(*list, char *));
	else if (s == 'i' || s == 'd')
		coun += kh_integer(&list);
	else if (s == 'b')
		coun += kh_binary(&list);
	else if (s == 'r')
		coun += kh_revstr(va_arg(*list, char *));
	else if (s == 'u')
		coun += kh_uint(&list);
	return (coun);
}

/**
 * kh_binary - form the decimal to binary
 * @list: the input
 * Return: int
*/
int kh_binary(va_list **list)
{
	unsigned int a = va_arg(**list, unsigned int);
	int i = 0, coun = 0;
	char str[34];

	if (a == 0)
	{
		write(1, "0", 1);
		coun++;
		return (coun);
	}
	else
	{
		while (a > 0)
		{
			str[coun] = (a % 2) + 48;
			coun++;
			a /= 2;
		}
		i = coun;
		while (--coun >= 0)
			kh_chaar(str[coun]);
		return (i);
	}
}

/**
 * kh_revstr - A function that prints the reverse of string
 * @str: input
 * Return: int
*/

int kh_revstr(char *str)
{
	int i = 0, coun = 0;

	if (!str)
		return (kh_string("(null)"));
	while (str[i] != '\0')
		i++;
	while (--i >= 0)
	{
		write(1, &str[i], 1);
		coun++;
	}
	return (coun);
}

/**
 * kh_uint - print unsigned int
 * @list: the input
 * Return: int
*/
int kh_uint(va_list **list)
{
	unsigned int a = va_arg(**list, unsigned int);
	unsigned int k = 0, d = 1000000000;
	int i = 0;

	if (a <= UINT_MAX)
		i += uint_ma(d, a, k);
	return (i);
}

/**
 * uint_ma - help uint in the print
 * @d: first input
 * @a: second input
 * @k: third input
 * Return: int
*/
int uint_ma(unsigned int d, unsigned int a, unsigned int k)
{
	int i = 0;
	char c = 48;

	while (d)
	{
		if (k == 0)
			k += a / d;
		if (k > 0)
		{
			c += (int) ((a / d) % 10);
			write(1, &c, 1);
			i++;
			c = 48;
		}
		if (d == 1)
			break;
		d /= 10;
	}
	if (k == 0 && a == 0)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
