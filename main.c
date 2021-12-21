#include "functions.h"

int main(int argc, char *argv[])
{
  t_map *map;
  int i;
  char *p;
  
  if (argc > 1)
  {
    i = 1;
    while (i < argc - 1)
    {
      validate_map(read_file(argv[i], p), map);
      resolve_map(map);
      print_map(map);
    }
   else if (argc == 1)
   {
     validate_map(read_input(argv[1], p), map);
     resolve_map(map);
     print_map(map);
   }
}
