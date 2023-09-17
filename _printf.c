#include "main.h"

/**_printf - a function that produces output
 * according to a format.
 *
 * @format: first input
 * @...: num of args
 *
 * Return:  number of characters printed
*/
int _printf(const char *format, ...){
	int i = 0;
	va_list list;

	if (!format)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
		}
		else
		{
			i++;
			/*while_struct*/
		}
		i++;
	}
}
