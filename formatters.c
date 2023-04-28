#include "main.h"
#include <stdarg.h>

/**
 * format_number - print formatted number
 *
 * @buf: print buffer
 * @n: number to print
 * @flags: parsed flags
 *
 * Return: number of bytes printed
 */
int format_number(buf_t *buf, int n, unsigned char flags)
{
	int count = 0;

	if (n < 0)
		count = putchar_buffered(buf, '-');
	else if (flags & FLAG_PLUS)
		count = putchar_buffered(buf, '+');
	else if (flags & FLAG_SPACE)
		count = putchar_buffered(buf, ' ');
	return (print_int(buf, _abs(n)) + count);
}

/**
 * format_unsign - print formatted unsigned integer
 *
 * @buf: print buffer
 * @n: number to print
 * @specifier: base to use
 * @fmt_opts: format specifier options
 *
 * Return: number of bytes printed
 */
int format_unsign(
	buf_t *buf,
	unsigned int n,
	char specifier,
	fmt_opt_t *fmt_opts
)
{
	int count = 0;

	switch (specifier)
	{
		case 'X':
		case 'x':
			count += print_hex(
				buf,
				n,
				specifier == 'X',
				fmt_opts->width,
				fmt_opts->flags & FLAG_HASH
			);
			break;
		case 'o':
			count += print_octal(buf, n, fmt_opts->flags & FLAG_HASH);
			break;
		case 'u':
			count += print_int(buf, n);
			break;
	}

	return (count);
}

/**
 * format_string - print formatted string
 *
 * @buf: print buffer
 * @str: string pointer to print
 *
 * Return: number of bytes printed
 */
int format_string(buf_t *buf, char *str)
{
	if (str == NULL)
		str = "(null)";
	return (puts_buffered(buf, str));
}

/**
 * format_custom - print formatted custom specifiers
 *
 * @buf: print buffer
 * @args: arguments list
 * @specifier: custom specifier
 *
 * Return: number of bytes printed
 */
int format_custom(buf_t *buf, va_list *args, char specifier)
{
	int count = 0;

	switch (specifier)
	{
		case 'b':
			count += print_binary(buf, va_arg(*args, unsigned int));
			break;
		case 'r':
			count += print_reverse(buf, va_arg(*args, char *));
			break;
		case 'R':
			count += print_reverse(buf, va_arg(*args, char *));
			break;
		case 'S':
			count += print_string(buf, va_arg(*args, char *));
			break;
	}

	return (count);
}
