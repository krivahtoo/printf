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

	printf("%ld\n", (long)n);
	_printf("%b\n", n);
	_printf("%b\n", 255);
	_printf("%b\n", 98);
	return (0);
}
