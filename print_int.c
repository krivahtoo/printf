#include "main.h"

/**
 * _abs - get absolute of a number
 *
 * @n: number
 *
 * Return: absolute number
 */
int _abs(int n)
{
	if (n < 0)
		return ((-1) * n);
	return (n);
}

/**
 * print_int - print a number.
 *
 * @n: number to print
 *
 * Return: number of bytes printed
 */
int print_int(unsigned int n)
{
	int count = 0;

	if (n != 0)
	{
		if (n / 10 != 0)
			count += print_int(n / 10);
		return (count + _putchar('0' + _abs(n % 10)));
	}
	else
		return (_putchar('0'));
}

/**
 * print_hex - print binary for unsigned integer
 *
 * @n: string pointer to print
 * @caps: if capitals are printed
 *
 * Return: number of bytes printed
 */
int print_hex(unsigned int n, int caps)
{
	int i = 0;
	char arr[9];
	char lower[] = "0123456789abcdef";
	char upper[] = "0123456789ABCDEF";

	while (i < 8)
	{
		int x = (n >> ((7 - i) * 4)) & 0xf;

		arr[i] = (caps == 1) ? upper[x] : lower[x];
		i++;
	}
	arr[8] = '\0';

	return (_puts(arr));
}

/**
 * print_octal - print octal value for unsigned integer
 *
 * @n: number to print
 *
 * Return: number of bytes printed
 */
int print_octal(unsigned int n)
{
	int i = 0, count = 0;
	int arr[32];

	while (n > 0)
	{
		arr[i++] = n % 8;
		n /= 8;
	}

	while (--i >= 0)
		count += _putchar(arr[i] + '0');

	return (count);
}
