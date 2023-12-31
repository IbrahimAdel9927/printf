#include "main.h"

/**
 * kh_mod - A Function prints the mod sign
 * @c: input char
 * Return: int
*/
int kh_mod(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * kh_chaar - A function that prints char
 * @c: input
 * Return: int
*/
int kh_chaar(char c)
{
	return (write(1, &c, 1));
}

/**
 * kh_string - A function prints string
 * @str: input
 * Return: int
*/
int kh_string(char *str)
{
	int i = 0;

	if (!str)
		return (kh_string("(null)"));
	while (str[i])
	{
		kh_chaar(str[i]);
		i++;
	}
	return (i);
}

/**
 * int_ma - a function that help kh_integer
 * @d: first input
 * @a: second input
 * @k: third input
 * Return: int
*/
int int_ma(int d, int a, int k)
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

/**
 * kh_integer - a function that print integers
 * @list: the input
 * Return: int
*/
int kh_integer(va_list **list)
{
	int a = va_arg(**list, int);
	int k = 0, i = 0, d = 1000000000;
	char c = 48;

	if (a >= INT_MIN && a <= INT_MAX)
	{
		if (a >= 0)
		{
			i += int_ma(d, a, k);
		}
		else
		{
			i++;
			write(1, "-", 1);
			while (d)
			{
				if (k == 0)
					k -= a / d;
				if (k > 0)
				{
					c -= (int) ((a / d) % 10);
					write(1, &c, 1);
					i++;
					c = 48;
				}
				if (d == 1)
					break;
				d /= 10;
			}
		}
	}
	return (i);
}

