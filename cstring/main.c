#include "string/cstring.h"

int main(void)
{
    str_t *hello = string_dup("hello");
    str_t *hello1 = string_dup("ape");

    str_t *app = string_concat(hello, hello1);
    string_print(app, stdout);

    putchar('\n');
    string_reverse(hello);
    string_print(hello, stdout);
    putchar('\n');
    printf("%s", chars_append("hello", "world"));
    putchar('\n');

   char *s = chars_dup("hello world");
   printf("%s", s);

   return 0;
}
