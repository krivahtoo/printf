#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *s);
int handle_format(const char *fmt, va_list *args, int *pos);

#endif /* MAIN_H */
