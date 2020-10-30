#include "cstring.h"

static void template_print(char *string, size_t length, FILE *file);
static void template_concat(char *string, char *left, char *right, size_t length_l, size_t length_r);
static void template_append(char *string, char *left, char *right, char *concat_space, size_t length_l, size_t length_r);
static void template_reverse(char *string, size_t length);
static size_t template_compare(char *string1, char *string2, size_t length1, size_t length2);

extern str_t *string_create(size_t length)
{
    str_t *string = (str_t*)malloc(sizeof(str_t));
    string->data = (char*)malloc(length);
    string->length = length;
    string->how_much = 0;

    return string;
}

extern void string_free(str_t *string)
{
    free(string->data);
    free(string);
}
extern size_t string_length(str_t *string)
{
    return string->length;
}

extern size_t chars_length(char *chars)
{
    return strlen(chars);
}

extern void string_print(str_t *string, FILE *file)
{
    template_print(string->data, string->length, file);
}

extern void chars_print(char *string, FILE *file)
{
    template_print(string, chars_length(string), file);
}

static void template_print(char *string, size_t length, FILE *file)
{
    fwrite(string, sizeof(char), length, file);
}

extern str_t *string_dup(const char *str)
{
    str_t *string = string_create(strlen(str));
    memcpy(string->data, str, string->length);
    string->how_much = string->length;

    return string;
}

extern char *string_pud(str_t *string)
{
    char *str = (char*)malloc(string->length);
    memcpy(str, string->data, string->length);

    *(str + string->length) = '\0';

    return str;
}

extern str_t *string_concat(str_t *left, str_t *right)
{
    str_t *string = string_create(left->length + right->length);
    template_concat(string->data, left->data, right->data, left->length, right->length);
    string->how_much = string->length;

    return string;
}

extern char *chars_concat(char *left, char *right)
{
    char *chars = (char*)malloc(chars_length(left) + chars_length(right));
    template_concat(chars, left, right, chars_length(left), chars_length(right) + 1);

    return chars;
}

static void template_concat(char *string, char *left, char *right, size_t length_l, size_t length_r)
{
    memcpy(string, left, length_l);
    memcpy(string + length_l, right, length_r);
}

extern str_t *string_append(str_t *left, str_t *right)
{
    str_t *space = string_dup(" ");
    str_t *string = string_create(left->length + right->length + 1);
    template_append(string->data, left->data, right->data, string_concat(space, right)->data, left->length, right->length + 2);
    string->how_much = string->length;
    string_free(space);

    return string;
}

extern char *chars_append(char *left, char *right)
{
    char *chars = (char*)malloc(chars_length(left) + chars_length(right) + 1);
    template_append(chars, left, right, chars_concat(" ", right), chars_length(left), chars_length(right) + 2);
    return chars;
}

static void template_append(char *string, char *left, char *right, char *concat_space, size_t length_l, size_t length_r)
{
    memcpy(string, left, length_l);
    memcpy(string + length_l, concat_space, length_r);
}

extern void string_reverse(str_t *string)
{
    template_reverse(string->data, string->length);
}

extern void chars_reverse(char *chars)
{
    template_reverse(chars, chars_length(chars));
}

static void template_reverse(char *string, size_t length)
{
    uint8_t c;
    size_t i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = c;
    }
}

extern size_t string_compare(str_t *string1, str_t *string2)
{
    template_compare(string1->data, string2->data, string1->length, string2->length);
}

extern size_t chars_compare(char *chars1, char *chars2)
{
    template_compare(chars1, chars2, chars_length(chars1), chars_length(chars2));
}

static size_t template_compare(char *string1, char *string2, size_t length1, size_t length2)
{
    size_t max_len = length1 > length2 ? length2 : length1;

    for (size_t i = 0; *string1 == *string2 && (i < max_len); i++, string1++, string2++)
    {
        if ((max_len - 1) == i)
            return 0;
    }

    return *string1 - *string2;
}
