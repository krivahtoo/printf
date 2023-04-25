#include <stdio.h>
#include <limits.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	long int n = UINT_MAX + 1024;
	int l1, l2;

	_printf("%o\n", n);
	printf("%o\n", n);
	_printf("%x\n", n);
	printf("%x\n", n);
	_printf("%o\n", 255);
	_printf("%o\n", 2);
	_printf("%x", 98);
	l1 = _printf("%o", 0);
	l2 = printf("%o", 0);
	if (l1 != l2)
		printf("Lengths defer: %d %d\n", l1, l2);
	return (0);
}
