#include "main.h"

/**
 * _printf - a function that produces output
 * according to a format.
 *
 * @format: first input
 * @...: num of args
 *
 * Return:  number of characters printed
*/
int _printf(const char *format, ...)
{
	int i = 0, coun = 0;
	va_list list;
	if (!format)
		return (-1);
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			coun++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				break;
			else if (format[i] == '%')
				coun += kh_mod(format[i]);
			else if (format[i] == 'c')
				coun += kh_chaar(&list);
			else if (format[i] == 's')
				coun += kh_string(&list);
			else if (format[i] == 'i' || format[i] == 'd')
				coun += kh_integer(&list);
		}
		i++;
	}
	va_end(list);
	return (coun);
}

