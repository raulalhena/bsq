#include "functions.h"

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

int ft_strlen(char *str)
{
  int i;
  
  i = 0;
  while (str[i])
    i++;
  return (i);
}

void  ft_putstr(char *str)
{
  int i;
  
  i = 0;
  while (str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
}

char    *ft_strcpy(char *dest, char *src)
{
    int i;
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
