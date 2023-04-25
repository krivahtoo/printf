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
int print_int(int n)
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

