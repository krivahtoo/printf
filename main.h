#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *s);
int print_int(int n);
int format_string(char *str);
int format_number(int n);
int handle_format(const char *fmt, va_list *args, int *pos);

#endif /* MAIN_H */
