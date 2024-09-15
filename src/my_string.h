#ifndef MY_STRING_H
#define MY_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define my_NULL (void *)0
#define my_size_t unsigned long

struct flags {
    char flag_plus;
    char flag_minus;
    char flag_space;
    char flag_length;
    char flag_width;
    char flag_dot;
};

void *my_memchr(const void *str, int c, my_size_t n);

int my_memcmp(const void *str1, const void *str2, my_size_t n);

void *my_memcpy(void *dest, const void *src, my_size_t n);

void *my_memset(void *str, int c, my_size_t n);

char *my_strncat(char *dest, const char *src, my_size_t n);

char *my_strchr(const char *str, int c);

int my_strncmp(const char *str1, const char *str2, my_size_t n);

char *my_strcpy(char *dest, const char *src);

char *my_strncpy(char *dest, const char *src, my_size_t n);

my_size_t my_strcspn(const char *str1, const char *str2);

char *my_strerror(int errnum);

my_size_t my_strlen(const char *str);

char *my_strpbrk(const char *str1, const char *str2);

char *my_strrchr(const char *str, int c);

char *my_strstr(const char *haystack, const char *needle);

char *my_strtok(char *str, const char *delim);

int my_sprintf(char *str, const char *format, ...);

void *my_to_upper(const char *str);

void *my_to_lower(const char *str);

void *my_insert(const char *src, const char *str, my_size_t start_index);

void *my_trim(const char *src, const char *trim_chars);

my_size_t my_itoa(char **number, long long n, int precision,
                  struct flags *flags);

my_size_t my_uitoa(char **number, unsigned long long n, int precision);

my_size_t my_itoa_reverse(char **number, long long n);

my_size_t my_uitoa_reverse(char **number, unsigned long long n);

my_size_t my_ftoa(char **number, double n, int precision,
                  struct flags *flags);

void my_reverse(char *s);

my_size_t my_read_number(const char *c, int *number);

my_size_t my_read_flags(const char *c, struct flags *flags, int *width,
                        int *precision);

void my_fill_spaces(char *str, int size);

void my_write_string(char **str, char *s, int width, char flag_minus,
                     my_size_t *length);

void my_flag_du_work(char c, unsigned long *un, long *n, struct flags *flags,
                     va_list *args);

#endif