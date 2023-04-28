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
 * rot13 - encodes a string using rot13.
 *
 * @s: string to encode
 *
 * Return: encoded string pointer
 */
char *rot13(char *s)
{
	int i;
	char *ptr = s;
	char ch[] = {'a', 'A'};

	while (*s)
	{
		for (i = 0; i < 2; i++)
			if (*s >= ch[i] && *s <= ch[i] + 25)
				*s = (((*s - ch[i]) - 13 + 26) % 26) + ch[i];
		s++;
	}
	return (ptr);
}
