#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct String
{
    char *data;
    size_t length;
    size_t how_much;
} str_t;

extern str_t *string_create(size_t length);
extern void string_free(str_t *string);

extern char *chars_create(size_t length);
extern void *chars_free(char *chars);

extern size_t string_length(str_t *string);
extern size_t chars_length(const char *chars);

extern void string_print(str_t *string, FILE *file);
extern void chars_print(char *string, FILE *file);

extern str_t *string_dup(const char *str);
extern char *string_pud(str_t *string);
extern char *chars_dup(const char *chars);

extern str_t *string_concat(str_t *left, str_t *right);
extern char *chars_concat(char *left, char *right);

extern str_t *string_append(str_t *left, str_t *right);
extern char *chars_append(char *left, char *right);

extern void string_reverse(str_t *string);
extern void chars_reverse(char *chars);

extern size_t string_compare(str_t *string1, str_t *string2);
extern size_t chars_compare(char *chars1, char *chars2);

#endif // CSTRING_H
