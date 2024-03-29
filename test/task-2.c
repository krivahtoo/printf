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
	unsigned int n = (unsigned int)INT_MAX + 1024;
	int l1, l2;

	printf("%ld\n", (long)n);
	_printf("%b\n", n);
	_printf("%b\n", 255);
	_printf("%b\n", 98);
	l1 = _printf("%b", 0);
	l2 = printf("0");
	if (l1 != l2)
		printf("Lengths defer: %d %d\n", l1, l2);
	return (0);
}
