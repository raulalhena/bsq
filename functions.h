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

char  *read_input(void);
char  *read_file(char *argv);
int validate_map(char *buff);
void  resolve_map(char *buff, t_map *map);
void  print_map(t_map map);
void  free_map(t_map *map);
