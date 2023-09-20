#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int _printf(const char *format, ...);
int kh_mod(char c);
int kh_chaar(char c);
int kh_string(char *str);
int int_ma(int d, int a, int k);
int kh_integer(va_list **list);
int option(char s, va_list *list);
int putch(char c);
int putstr(char *str);
int kh_binary(va_list **list);
int kh_revstr(char *str);
int uint_ma(unsigned int d, unsigned int a, unsigned int k);
int kh_uint(va_list **list);
int kh_oct(va_list **list);
int kh_hex(va_list **list);
int kh_HEX(va_list **list);

#endif/*the_end*/
