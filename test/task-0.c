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
	int l1, l2;

	_printf("%!\n");
	printf("%!\n");
	_printf("%K\n");
	printf("%K\n");
	l1 = _printf("%");
	l2 = printf("%");
	if (l1 != l2)
		printf("Lengths defer: %d %d\n", l1, l2);
	l1 = _printf(NULL);
	l2 = printf(NULL);
	if (l1 != l2)
		printf("Lengths defer: %d %d\n", l1, l2);
	return (0);
}
