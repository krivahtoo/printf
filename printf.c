#include "main.h"
#include <stdarg.h>

/**
 * _printf - print formatted output
 *
 * @format: format string.
 *
 * Return: the number of characters printed, -1 on failure
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list args;
	buf_t buffer = { NULL, 0 };

	buffer.p = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer.p == NULL)
		return (-1);

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			int x;

			if (format[i + 1] == '\0')
				return (-1);
			x = handle_format(format, &buffer, &args, &i);

			if (x >= 0)
			{
				count += x;
				continue;
			}
		}
		count += putchar_buffered(&buffer, format[i]);
		i++;
	}

	va_end(args);

	count += print_buffer(&buffer);

	free(buffer.p);

	return (count);
}
