#include "functions.h"

char    *read_input(char **p)
{
    int a;
    a = read(0, *p, SIZE);
    *p = malloc(sizeof(char) * a);
    if (!*p)
        return ("Memory error\n");
    return (*p);
}
