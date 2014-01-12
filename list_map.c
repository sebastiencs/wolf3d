/*
** list_linked.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Tue Dec 31 13:46:59 2013 Sebastien Chapuis
** Last update Sun Jan 12 13:06:32 2014 sebastien
*/

#include <stdlib.h>
#include "wolf.h"

static t_map	*create_elem(char *str, int line)
{
  t_map		*new;

  new = NULL;
  if ((new = (t_map*)malloc(sizeof(*new))))
  {
    new->line = line;
    new->str = str;
    new->next = NULL;
  }
  return (new);
}

int		push_map(t_map **map, char *str, int line)
{
  t_map		*tmp;

  tmp = *map;
  if (tmp)
  {
    while (tmp->next)
      tmp = tmp->next;
    if ((tmp->next = create_elem(str, line)))
      return (0);
  }
  else
    if ((*map = create_elem(str, line)))
      return (0);
  my_puterror(ALLOC_ERROR);
  return (FAILED);
}

void		free_list(t_map *list)
{
  t_map		*tmp;

  while (list)
  {
    tmp = list;
    list = list->next;
    free(tmp);
  }
}
