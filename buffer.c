#include "main.h"
#include <unistd.h>

/**
 * print_buffer - print all contents of buffer
 *
 * @buf: buffer to print
 *
 * Return: number of printed characters
 */
int print_buffer(buf_t *buf)
{
	int count;

	write(STDOUT_FILENO, buf->p, buf->pos);
	count = buf->pos;
	buf->pos = 0;
	return (count);
}

/**
 * putchar_buffered - print buffered char
 *
 * @buf: buffer to print
 * @c: character to print
 *
 * Return: number of printed characters
 */
int putchar_buffered(buf_t *buf, char c)
{
	buf->p[(buf->pos)++] = c;

	if (buf->pos >= BUFFER_SIZE)
		return (print_buffer(buf));

	return (0);
}

/**
 * puts_buffered - print buffered string
 *
 * @buf: buffer to print
 * @s: string to print
 *
 * Return: number of printed characters
 */
int puts_buffered(buf_t *buf, char *s)
{
	int i = 0, n = 0;

	for (; s[i] != '\0'; i++)
		n += putchar_buffered(buf, s[i]);

	return (n);
}
