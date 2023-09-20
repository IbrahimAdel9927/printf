#include "main.h"

/**
 * kh_oct - form decimal to octal
 * @list: the input
 * Return: int
*/
int kh_oct(va_list **list)
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
			str[coun] = (a % 8) + 48;
			coun++;
			a /= 8;
		}
		i = coun;
		while (--coun >= 0)
			kh_chaar(str[coun]);
		return (i);
	}
}

/**
 * kh_hex - form the decimal num to hexadecimal
 * @list: the input
 * Return: int
*/
int kh_hex(va_list **list)
{
	unsigned int a = va_arg(**list, unsigned int);
	int i = 0, coun = 0, c;
	char str[34], flag[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

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
			c = (a % 16);
			if (c > 9)
				str[coun] = flag[c - 10];
			else
				str[coun] = c + 48;
			coun++;
			a /= 16;
		}
		i = coun;
		while (--coun >= 0)
			kh_chaar(str[coun]);
		return (i);
	}
}

/**
 * kh_HEX - form the decimal num to hexadecimal
 * @list: the input
 * Return: int
*/

int kh_HEX(va_list **list)
{
	unsigned int a = va_arg(**list, unsigned int);
	int i = 0, coun = 0, c;
	char str[34], flag[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

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
			c = (a % 16);
			if (c > 9)
				str[coun] = flag[c - 10];
			else
				str[coun] = c + 48;
			coun++;
			a /= 16;
		}
		i = coun;
		while (--coun >= 0)
			kh_chaar(str[coun]);
		return (i);
	}
}

/**
 * kh_rot13 - make the rot 13
 * @str: the input
 * Return: int
*/
int kh_rot13(char *str)
{
	int coun = 0, flag;

	if (!str)
		return (kh_string("(null)"));
	while (str[coun])
	{
		if (str[coun] >= 65 && str[coun] <= 90)
		{
			flag = str[coun] + 13;
			if (flag <= 90)
				kh_chaar(flag);
			else
				kh_chaar(flag - 26);
		}
		else if (str[coun] >= 97 && str[coun] <= 122)
		{
			flag = str[coun] + 13;
			if (flag <= 122)
				kh_chaar(flag);
			else
				kh_chaar(flag - 26);
		}
		else
			kh_chaar(str[coun]);
		coun++;
	}
	return (coun);
}

