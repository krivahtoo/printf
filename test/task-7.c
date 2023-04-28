#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	_printf("%+ d ", 1024);
	printf("%+ d\n", 1024);
	_printf("%#x ", 1024);
	printf("%#x\n", 1024);
	_printf("%#06x ", 4);
	printf("%#06x\n", 4);
	_printf("%06d ", 1024);
	printf("%06d\n", 1024);
	_printf("%#lo ", 1024L);
	printf("%#lo\n", 1024L);
	len = _printf("%+d ", 1024);
	len2 = printf("%+d\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
