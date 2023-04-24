#include "main.h"

/**
 * _puts - print string to stdout
 *
 * @s: string pointer
 *
 * Return: bytes written
 */
int _puts(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		n += _putchar(*s);
		s++;
	}
	return (n);
}
