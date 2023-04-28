#include "main.h"
#include <stdint.h>

/**
 * print_string - print custom conversion specifier
 *
 * @buf: print buffer
 * @str: string to print
 *
 * Return: number of printed characters
 */
int print_string(buf_t *buf, char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		if (*str >= 127 || *str < 32)
		{
			n += puts_buffered(buf, "\\x");
			n += print_hex(buf, (unsigned int)*str, 1, 2, 0);
		}
		else
		{
			n += putchar_buffered(buf, *str);
		}
		str++;
	}

	return (n);
}

/**
 * print_address - print address of a pointer
 *
 * @buf: print buffer
 * @p: pointer
 *
 * Return: number of printed characters
 */
int print_address(buf_t *buf, void *p)
{
	int n = 0;
	uintptr_t address;

	if (p == NULL)
		n += puts_buffered(buf, "(nil)");
	else
	{
		address = (uintptr_t)p;
		n += print_hex(buf, address, 0, 0, 1);
	}

	return (n);
}

/**
 * print_reverse - print reversed string
 *
 * @buf: print buffer
 * @str: string pointer
 *
 * Return: number of printed characters
 */
int print_reverse(buf_t *buf, char *str)
{
	int i = 0, n = 0;

	while (str[i] != '\0')
		i++;

	while (--i > 0)
		n += putchar_buffered(buf, str[i]);

	return (n);
}

/**
 * print_rot13 - print reversed string
 *
 * @buf: print buffer
 * @str: string pointer
 *
 * Return: number of printed characters
 */
int print_rot13(buf_t *buf, char *str)
{
	char *s = rot13(str);

	return (puts_buffered(buf, s));
}
