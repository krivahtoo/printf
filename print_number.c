#include "main.h"

/**
 * print_int - print a number.
 *
 * @buf: print buffer
 * @n: number to print
 *
 * Return: number of bytes printed
 */
int print_int(buf_t *buf, unsigned int n)
{
	int count = 0;

	if (n != 0)
	{
		if (n / 10 != 0)
			count += print_int(buf, n / 10);
		return (count + putchar_buffered(buf, '0' + _abs(n % 10)));
	}
	else
		return (putchar_buffered(buf, '0'));
}

/**
 * print_hex - print binary for unsigned integer
 *
 * @buf: print buffer
 * @n: string pointer to print
 * @caps: if capitals are printed
 * @length: lenght of characters
 * @prefix: if prefix is added
 *
 * Return: number of bytes printed
 */
int print_hex(
	buf_t *buf,
	unsigned long int n,
	int caps,
	int length,
	int prefix
)
{
	int i = 0, count = 0;
	char arr[16] = { 0 };
	char lower[] = "0123456789abcdef";
	char upper[] = "0123456789ABCDEF";

	if (n == 0)
		arr[i++] = 0;

	if (prefix)
		count += puts_buffered(buf, caps ? "0X" : "0x");

	while (n > 0)
	{
		arr[i++] = n % 16;
		n /= 16;
	}

	if (length > 0 && length < 16)
		i = prefix && length > 2 ? length - 2 : length;

	while (i > 0)
	{
		int x = arr[--i];

		count += putchar_buffered(buf, caps ? upper[x] : lower[x]);
	}

	return (count);
}

/**
 * print_octal - print octal value for unsigned integer
 *
 * @buf: print buffer
 * @n: number to print
 * @prefix: if prefix is added
 *
 * Return: number of bytes printed
 */
int print_octal(buf_t *buf, unsigned int n, int prefix)
{
	int i = 0, count = 0;
	int arr[32];

	if (n == 0)
		arr[i++] = 0;
	else if (prefix)
		count += putchar_buffered(buf, '0');

	while (n > 0)
	{
		arr[i++] = n % 8;
		n /= 8;
	}

	while (i > 0)
		count += putchar_buffered(buf, arr[--i] + '0');

	return (count);
}

/**
 * print_binary - print binary for unsigned integer
 *
 * @buf: print buffer
 * @n: string pointer to print
 *
 * Return: number of bytes printed
 */
int print_binary(buf_t *buf, unsigned int n)
{
	int i = 0, count = 0;
	int arr[32];

	if (n == 0)
		arr[i++] = 0;

	while (n > 0)
	{
		arr[i++] = n % 2;
		n /= 2;
	}

	while (i > 0)
		count += putchar_buffered(buf, arr[--i] + '0');

	return (count);
}
