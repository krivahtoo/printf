#include "main.h"
#include <stdarg.h>

/**
 * handle_flags - handle flags
 *
 * @fmt: format string pointer
 * @fmt_opt: options to update
 * @pos: current possition in fmt
 */
void handle_flags(
		const char *fmt,
		fmt_opt_t *fmt_opt,
		int *pos)
{
	while (fmt[*pos] == '-' || fmt[*pos] == '+' ||
			fmt[*pos] == ' ' || fmt[*pos] == '#' || fmt[*pos] == '0')
	{
		switch (fmt[*pos])
		{
			case '-':
				fmt_opt->flags |= FLAG_MINUS;
				break;
			case '+':
				fmt_opt->flags |= FLAG_PLUS;
				break;
			case ' ':
				fmt_opt->flags |= FLAG_SPACE;
				break;
			case '#':
				fmt_opt->flags |= FLAG_HASH;
				break;
			case '0':
				fmt_opt->flags |= FLAG_ZERO;
				break;
		}
		*pos += 1;
	}
}

/**
 * handle_precision - handle precition
 *
 * @fmt: format string pointer
 * @args: arguments list
 * @fmt_opt: options to update
 * @pos: current possition in fmt
 */
void handle_precision(
		const char *fmt,
		va_list *args,
		fmt_opt_t *fmt_opt,
		int *pos)
{
	*pos += 1;
	if (fmt[*pos] == '*')
	{
		fmt_opt->precision = va_arg(*args, int);
		*pos += 1;
	}
	else
	{
		fmt_opt->precision = 0;
		while (fmt[*pos] >= '0' && fmt[*pos] <= '9')
		{
			fmt_opt->precision = fmt_opt->precision * 10 + (fmt[*pos] - '0');
			*pos += 1;
		}
	}
}

/**
 * handle_options - handle conversion specifier options
 *
 * @fmt: format string pointer
 * @args: arguments list
 * @fmt_opt: options to update
 * @pos: current possition in fmt
 */
void handle_options(
		const char *fmt,
		va_list *args,
		fmt_opt_t *fmt_opt,
		int *pos)
{
	handle_flags(fmt, fmt_opt, pos);

	if (fmt[*pos] == '*')
	{
		fmt_opt->width = va_arg(*args, int);
		*pos += 1;
	}
	else
	{
		while (fmt[*pos] >= '0' && fmt[*pos] <= '9')
		{
			fmt_opt->width = fmt_opt->width * 10 + (fmt[*pos] - '0');
			*pos += 1;
		}
	}

	/* precision */
	if (fmt[*pos] == '.')
	{
		handle_precision(fmt, args, fmt_opt, pos);
	}

	/* length modifiers */
	if (fmt[*pos] == 'l')
	{
		fmt_opt->length = 1;
		*pos += 1;
	}
	else if (fmt[*pos] == 'h')
	{
		fmt_opt->length = 0;
		*pos += 1;
	}
}

/**
 * handle_specifier - handle conversion specifier
 *
 * @specifier: conversion specifier
 * @buf: print buffer
 * @args: arguments list
 * @fmt_opt: format specifier options
 *
 * Return: length of bytes printed, -1 on failure.
 */
int handle_specifier(
	char specifier,
	buf_t *buf,
	va_list *args,
	fmt_opt_t *fmt_opt
)
{
	int n = 0;

	switch (specifier)
	{
		case 'c':
			n += putchar_buffered(buf, (unsigned char)va_arg(*args, int));
			break;
		case 's':
			n += format_string(buf, va_arg(*args, char *));
			break;
		case 'd':
		case 'i':
			n += format_number(buf, va_arg(*args, int), fmt_opt->flags);
			break;
		case 'b':
		case 'S':
		case 'r':
		case 'R':
			n += format_custom(buf, args, specifier);
			break;
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			n += format_unsign(buf, va_arg(*args, unsigned int), specifier, fmt_opt);
			break;
		case 'p':
			n += print_address(buf, va_arg(*args, void *));
			break;
		case '%':
			n += putchar_buffered(buf, '%');
			break;
		default:
			return (-1);
	}
	return (n);
}

/**
 * handle_format - handle a single format string starting with '%'
 *
 * @fmt: pointer to the format string
 * @buf: print buffer
 * @args: arguments list
 * @pos: points to the '%' location on fmt string
 *
 * Return: length of bytes printed, -1 on failure.
 */
int handle_format(const char *fmt, buf_t *buf, va_list *args, int *pos)
{
	int n = 0;
	char specifier;
	fmt_opt_t fmt_opt = { 0, 0, 0, 0, 0 };

	if (fmt[*pos] == '%')
	{
		*pos += 1;

		handle_options(fmt, args, &fmt_opt, pos);

		specifier = fmt[*pos];
		n = handle_specifier(specifier, buf, args, &fmt_opt);
		if (n < 0)
		{
			*pos -= 1;
			return (-1);
		}

		*pos += 1;
	}
	return (n);
}
