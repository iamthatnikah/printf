#include "main.h"

/**
 * _printf - Function to format output conversion and print data.
 * @format: input string.
 *
 * Return: chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int x = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[x] == '%' && !format[x + 1]))
		return (-1);
	if (!format[x])
		return (0);
	for (x = 0; format && format[x]; x++)
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, x + 1);
				if (function == NULL)
				{
					if (format[x + 1] == ' ' && !format[x + 2])
						return (-1);
					handl_buf(buffer, format[x], ibuf), len++, x--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					x += ev_print_func(format, x + 1);
				}
			} x++;
		}
		else
			handl_buf(buffer, format[x], ibuf), len++;
		for (xbuf = len; xbuf > 1024; xbuf -= 1024)
			;
	}
	print_buf(buffer, xbuf), free(buffer), va_end(arguments);
	return (len);
}
