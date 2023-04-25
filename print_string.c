#include "main.h"

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
			n += print_hex(buf, (unsigned int)*str, 1, 2);
		}
		else
		{
			n += putchar_buffered(buf, *str);
		}
		str++;
	}

	return (n);
}
