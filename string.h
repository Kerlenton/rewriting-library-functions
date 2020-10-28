#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct String
{
    uint8_t *data;
    uint8_t length;
    uint8_t how_much;
} str_t;

str_t *string_create(uint8_t length)
{
    str_t *string = (str_t*)malloc(sizeof(str_t));
    string->data = (uint8_t*)malloc(sizeof(length));
    string->length = length;
    string->how_much = 0;

    return string;
}

void string_free(str_t *string)
{
    free(string->data);
    free(string);
}

uint8_t string_len(str_t *string)
{
    return string->length;
}

void print_string(str_t *string, FILE *file)
{
    fwrite(string->data, sizeof(uint8_t), (size_t)string->length, file);
}

size_t str_len(const char *string)
{
    size_t count = 0;
    while (*string++ != '\0')
    {
        ++count;
    }

    return count;
}

str_t *string_dup(const char *str)
{
    str_t *string = string_create((uint8_t)str_len(str));
    memcpy(string->data, str, string->length);
    string->how_much = string->length;

    return string;
}

str_t *string_concat(str_t *left, str_t *right)
{
    str_t *string = string_create(left->length + right->length);
    memcpy(string->data, left->data, left->length);
    memcpy(string->data + left->length, right->data, right->length);
    string->how_much = string->length;

    return string;
}

void reverse(str_t *string)
{
    uint8_t c;
    size_t i, j;
    
    for (i = 0, j = (size_t)string->length - 1; i < j; i++, j--)
    {
        c = *(string->data + i);
        *(string->data + i) = *(string->data + j);
        *(string->data + j) = c; 
    }
}

int string_fread(char *name, char *dest)
{
    int i = 0;
    FILE *file;
    
    if ((file = fopen(name, "r")) == NULL)
        return 1;
    
    while ((feof(file) == 0) && (ferror(file) == 0))
    {
        dest[i] = getc(file);
        i++;
    }
    
    if (i != str_len(dest))
        return 1
        
        
    dest[i] = '\0';
    
    return 0;
}

int main(void)
{
    str_t *hello = string_dup("hello");
    squeeze(hello, 'l');
    print_string(hello, stdout);
    
    return 0;
}
