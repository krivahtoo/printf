#include "main.h"
#include <stdarg.h>

/**
 * handle_format - handle a single format string starting with '%'
 *
 * @fmt: pointer to the format string
 * @args: arguments list
 * @pos: points to the '%' location on fmt string
 *
 * Return: length of bytes printed, -1 on failure.
 */
int handle_format(const char *fmt, va_list *args, int *pos)
{
	int n = 0, num;
	char specifier;
	char *str;
	unsigned char ch;

	if (fmt[*pos] == '%')
	{
		*pos += 1;
		specifier = fmt[*pos];

		switch (specifier)
		{
			case 'c':
				ch = (unsigned char)va_arg(*args, int);
				n += _putchar(ch);
				break;
			case 's':
				str = va_arg(*args, char *);
				n += format_string(str);
				break;
			case 'd':
			case 'i':
				num = va_arg(*args, int);
				n += format_number(num);
				break;
			case '%':
				n += _putchar('%');
				break;
			default:
				*pos -= 1;
				return (-1);
		}
		*pos += 1;
	}

	return (n);
}
