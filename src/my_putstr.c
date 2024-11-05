#include "../includes/all.h"

int my_putstr(char const *str)
{
    int d = 0;

    while (str[d] != '\0') {
        my_putchar(str[d]);
        d++;
    }
    return (0);
}
