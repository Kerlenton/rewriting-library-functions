#include "cstring.h"

static void template_print(char *string, size_t length, FILE *file);
static void template_concat(char *string, char *left, char *right, size_t length_l, size_t length_r);
static void template_append(char *string, char *left, char *right, char *concat_space, size_t length_l, size_t length_r);
static void template_reverse(char *string, size_t length);
static size_t template_compare(char *string1, char *string2, size_t length1, size_t length2);
static size_t template_copy(char *string1, char *string2, size_t length1, size_t length2);

extern str_t *string_create(size_t length)
{
    str_t *string = (str_t*)malloc(sizeof(str_t));
    string->data = (char*)malloc(length + 1);
    string->length = length;
    string->how_much = 0;

    return string;
}

extern void string_free(str_t *string)
{
    free(string->data);
    free(string);
}

extern char *chars_create(size_t length)
{
    char *chars = (char*)malloc(length + 1);

    return chars;
}

extern void *chars_free(char *chars)
{
    free(chars);
}

extern size_t string_length(str_t *string)
{
    return string->length;
}

extern size_t chars_length(const char *chars)
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
    str_t *string = string_create(chars_length(str));
    memcpy(string->data, str, string->length + 1);
    string->how_much = string->length;

    return string;
}

extern char *chars_dup(const char *chars)
{
    char *str = chars_create(chars_length(chars));
    memcpy(str, chars, chars_length(chars) + 1);

    return str;
}

extern char *string_pud(str_t *string)
{
    char *str = chars_create(string->length);
    memcpy(str, string->data, string->length + 1);

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
    char *chars = chars_create(chars_length(left) + chars_length(right));
    template_concat(chars, left, right, chars_length(left), chars_length(right));

    return chars;
}

static void template_concat(char *string, char *left, char *right, size_t length_l, size_t length_r)
{
    memcpy(string, left, length_l);
    memcpy(string + length_l, right, length_r + 1);
}

extern str_t *string_append(str_t *left, str_t *right)
{
    str_t *space = string_dup(" ");
    str_t *string = string_create(left->length + right->length + 1);

    template_append(string->data, left->data, right->data, string_concat(space, right)->data, left->length, right->length);

    string->how_much = string->length;
    string_free(space);

    return string;
}

extern char *chars_append(char *left, char *right)
{
    char *chars = chars_create(chars_length(left) + chars_length(right) + 1);
    template_append(chars, left, right, chars_concat(" ", right), chars_length(left), chars_length(right));

    return chars;
}

static void template_append(char *string, char *left, char *right, char *concat_space, size_t length_l, size_t length_r)
{
    memcpy(string, left, length_l);
    memcpy(string + length_l, concat_space, length_r + 2);
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

extern void string_copy(str_t *string1, str_t *string2)
{
    string1->how_much = template_copy(string1->data, string2->data, string1->length, string2->length);
    string1->length = string2->length;
}

extern void chars_copy(char *chars1, char *chars2)
{
    template_copy(chars1, chars2, chars_length(chars1), chars_length(chars2));
}

static size_t template_copy(char *string1, char *string2, size_t length1, size_t length2)
{
    size_t temp = length1;

    if (length2 > temp)
    {
        while (length2 > temp)
            temp *= 2;

        string1 = (char*)realloc(string1, temp);
    }

    memcpy(string1, string2, length2 + 1);

    return temp;
}
