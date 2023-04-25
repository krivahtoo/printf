#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *s);
int _abs(int n);
int print_int(unsigned int n);
int print_hex(unsigned int n, int caps);
int print_octal(unsigned int n);
int format_string(char *str);
int format_number(int n);
int format_binary(unsigned int n);
int format_unsigned(unsigned int n, char specifier);
int handle_format(const char *fmt, va_list *args, int *pos);

#endif /* MAIN_H */
