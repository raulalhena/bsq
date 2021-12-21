#include "functions.h"

int ft_atoi(char *str)
{
    int number;

    number = 0;
    while (*str >= '0' && *str <= '9')
    {
        number = number * 10;
        number = number + (*str - '0');
        str++;
    }
    return (number);
}