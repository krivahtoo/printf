#include "main.h"

/**
 * format_number - print formatted number
 *
 * @n: number to print
 *
 * Return: number of bytes printed
 */
int format_number(int n)
{
	int count = 0;

	if (n < 0)
		count = _putchar('-');
	return (print_int(n) + count);
}

/**
 * format_string - print formatted string
 *
 * @s: string pointer to print
 *
 * Return: number of bytes printed
 */
int format_string(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (_puts(str));
}
