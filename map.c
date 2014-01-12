/*
** map.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Tue Dec 31 13:39:14 2013 Sebastien Chapuis
** Last update Sun Jan 12 18:21:37 2014 sebastien
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "wolf.h"

static int	check_first_last(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
  {
    if (!(i % 2) && str[i] != '1')
    {
      my_puterror("First and last line must be completed with '1'\n");
      return (FAILED);
    }
    if (i % 2 && str[i] != ' ')
    {
      my_puterror("error: caracter must be '0', ' ' or '1'\n");
      return (FAILED);
    }

    i = i + 1;
  }
  return (0);
}

static int	check_map(t_map *list_map)
{
  t_map		*tmp;
  unsigned int	nb_col;

  tmp = list_map;
  if (list_map == NULL)
    return (my_puterror(MAP_ERROR));
  nb_col = my_strlen(list_map->str);
  if (check_first_last(list_map->str) == FAILED)
    return (FAILED);
  while (tmp)
  {
    if (tmp->str[0] == '0' || tmp->str[0] == ' '
	|| tmp->str[nb_col - 1] == '0' || tmp->str[nb_col - 1] == ' ')
      return (my_puterror("map error: No '0' or ' ' on side of map\n"));
    if (my_strlen(tmp->str) != nb_col)
      return (my_puterror("map error: columns's nbs are different\n"));
    tmp = tmp->next;
  }
  return (0);
}

static int	**save_map(t_map *list_map, int nb_line, int nb_col, int i)
{
  int		**map;
  t_map		*tmp;
  int		j;
  int		z;

  if ((map = (int**)malloc(sizeof(int*) * (nb_line + 1))) == NULL)
    return (NULL);
  tmp = list_map;
  while (tmp)
  {
    z = 0;
    j = 0;
    if ((map[i] = (int*)malloc(sizeof(int) * nb_col)) == NULL)
      return (NULL);
    while (j < nb_col)
    {
      map[i][j] = (tmp->str[z] != ' ' && tmp->str[z] != '0') ? (1) : (0);
      z = z + 2;
      j = j + 1;
    }
    i = i + 1;
    tmp = tmp->next;
  }
  map[i] = NULL;
  return (map);
}

static int	get_nb_line(t_map *list)
{
  int		i;
  t_map		*tmp;

  i = 0;
  tmp = list;
  while (tmp)
  {
    i = i + 1;
    tmp = tmp->next;
  }
  return (i);
}

int		**get_map(char *filename, t_env *env)
{
  int		i;
  int		fd;
  int		**map;
  t_map		*list_map;
  char		*tmp;

  i = 0;
  list_map = NULL;
  if ((fd = open(filename, O_RDONLY)) == FAILED)
  {
    my_puterror(FILE_ERROR);
    return (NULL);
  }
  while ((tmp = get_next_line(fd)))
    if ((push_map(&list_map, tmp, i++)) == FAILED)
      return (NULL);
  if (check_map(list_map) == FAILED)
    return (NULL);
  if ((map = save_map(list_map, i, (my_strlen(list_map->str) + 1) / 2, 0))
      == NULL)
    my_puterror(ALLOC_ERROR);
  env->size_x = (my_strlen(list_map->str) + 1) / 2;
  env->size_y = get_nb_line(list_map);
  free_list(list_map);
  return (map);
}
