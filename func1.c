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
	return (coun);
}
