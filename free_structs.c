/*
** free_structs.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Sat Jan 11 01:34:18 2014 sebastien
** Last update Sat Jan 11 01:39:05 2014 sebastien
*/

#include <stdlib.h>
#include "wolf.h"

void		free_map(int **map)
{
  int		i;

  i = 0;
  while (map[i])
  {
    free(map[i]);
    i = i + 1;
  }
}

void		free_func(t_functions *list)
{
  t_functions	*tmp;

  tmp = list;
  while (list)
  {
    tmp = list->next;
    free(list);
    list = tmp;
  }
}
