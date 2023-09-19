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
int kh_chaar(va_list *list);
int kh_string(va_list *list);


#endif/*the_end*/
