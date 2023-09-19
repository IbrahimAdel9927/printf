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
 * list: input
 * Return: int
*/
int kh_chaar(va_list *list)
{
	char c = va_arg(*list, int);

	write(1, &c, 1);
	return (1);
}

/**
 * kh_string - A function prints string
 * list: input
 * Return: int
*/
int kh_string(va_list *list)
{
	char *str = va_arg(*list, char*);
	int i = 0;

	while (str[i] != '\0')
		i++;
	write(1, str, i);
	return (i);
}

