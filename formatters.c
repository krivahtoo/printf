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
