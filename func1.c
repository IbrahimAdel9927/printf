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
