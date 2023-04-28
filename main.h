#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define FLAG_MINUS  (1 << 0)
#define FLAG_PLUS   (1 << 1)
#define FLAG_SPACE  (1 << 2)
#define FLAG_HASH   (1 << 3)
#define FLAG_ZERO   (1 << 4)

/**
 * struct format_options - format specifier options
 *
 * @flags: conversion flags
 * @dollar: dollar sign passed
 * @width: field width
 * @precision: precision
 * @length: length modifiers
 */
typedef struct format_options
{
	unsigned char flags;
	char dollar;
	int width;
	int precision;
	int length;
} fmt_opt_t;

/**
 * struct buffer - contain buffer and current position on buffer
 *
 * @p: pointer to buffered characters
 * @pos: current position
 */
typedef struct buffer
{
	char *p;
	int pos;
} buf_t;

int print_buffer(buf_t *buf);
int putchar_buffered(buf_t *buf, char c);
int puts_buffered(buf_t *buf, char *p);

int _printf(const char *format, ...);

int _abs(int n);
char *rot13(char *s);

int print_int(buf_t *buf, unsigned int n);
int print_hex(
	buf_t *buf,
	unsigned long int n,
	int caps,
	int length,
	int prefix
);
int print_octal(buf_t *buf, unsigned int n, int prefix);
int print_binary(buf_t *buf, unsigned int n);
int print_string(buf_t *buf, char *str);
int print_address(buf_t *buf, void *p);
int print_reverse(buf_t *buf, char *str);

int format_string(buf_t *buf, char *str);
int format_number(buf_t *buf, int n, unsigned char flags);
int format_unsign(
	buf_t *buf,
	unsigned int n,
	char specifier,
	fmt_opt_t *fmt_opt
);
int format_custom(buf_t *buf, va_list *args, char specifier);

void handle_precision(
	const char *fmt,
	va_list *args,
	fmt_opt_t *fmt_opt,
	int *pos
);
void handle_options(
	const char *fmt,
	va_list *args,
	fmt_opt_t *fmt_opt,
	int *pos
);
int handle_specifier(
	char specifier,
	buf_t *buf,
	va_list *args,
	fmt_opt_t *fmt_opt
);
int handle_format(const char *fmt, buf_t *buf, va_list *args, int *pos);

#endif /* MAIN_H */
