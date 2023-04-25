#include "main.h"
#include <stdarg.h>

/**
 * _printf - print formatted output
 *
 * @format: format string.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		RETURN (0);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			int x = handle_format(format, &args, &i);

			if (x > 0)
			{
				count += x;
				continue;
			}
		}
		count += _putchar(format[i]);
		i++;
	}

	va_end(args);

	return (count);
}
