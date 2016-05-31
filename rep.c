#include <stdio.h>

char *
foo(const char *s)
{
    int a[256] = {0};
    const char *temp = s;
    char c;
    while (*temp) {
        char ch = *temp;
        a[ch]++;
        temp++;
    }

    temp = s;
    while(*temp) {
        char ch = *temp;
        if (a[ch] == 1) {
            c = ch;
            return c;
        }
    }
}
