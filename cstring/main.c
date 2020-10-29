#include "string/cstring.h"

int main(void)
{
    str_t *hello = string_dup("hello");
    str_t *hello1 = string_dup("ape");

   // string_copy(hello, hello1);

    //printf("%d", sizeof(uint8_t));
   // str_t *app = string_concat(hello, hello);
   // string_print(app, stdout);

   printf("%s", chars_append("hello", "world"));

    return 0;
}
