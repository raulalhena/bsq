#include <stdio.h>
#include <unistd.h>
#include <fnctl.h>
#include <stdlib.h>

typedef struct s_map{
  char **map;
  int start_x;
  int start_y;
  int max;
  int map_size;
} t_map;

char  *read_input(void); // Miguel
char  *read_file(char *argv); // Miguel
int   validate_map(char *buff); // Albert
void  resolve_map(char *buff, t_map *map); // Gabriel
void  print_map(t_map map); // Julia
void  free_map(t_map *map); // Julia
int   ft_atoi(char *str); // to customize
int   ft_strlen(char *str);
void  ft_putchar(char c);
void  ft_putstr(char *str);
