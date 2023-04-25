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
	return (print_int(_abs(n)) + count);
}

/**
 * format_unsigned - print formatted unsigned integer
 *
 * @n: number to print
 * @specifier: base to use
 *
 * Return: number of bytes printed
 */
int format_unsigned(unsigned int n, char specifier)
{
	int count = 0;

	switch (specifier)
	{
		case 'X':
		case 'x':
			count += print_hex(n, specifier == 'X');
			break;
		case 'o':
			count += print_octal(n);
			break;
		case 'u':
			count += print_int(n);
			break;
	}

	return (count);
}

/**
 * format_string - print formatted string
 *
 * @str: string pointer to print
 *
 * Return: number of bytes printed
 */
int format_string(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (_puts(str));
}

/**
 * format_binary - print binary for unsigned integer
 *
 * @n: string pointer to print
 *
 * Return: number of bytes printed
 */
int format_binary(unsigned int n)
{
	int i = 0, count = 0;
	int arr[32];

	while (n > 0)
	{
		arr[i++] = n % 2;
		n /= 2;
	}

	while (--i >= 0)
		count += _putchar(arr[i] + '0');

	return (count);
}
