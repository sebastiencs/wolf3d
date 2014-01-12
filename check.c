/*
** usage.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Sat Jan 11 17:46:52 2014 sebastien
** Last update Sun Jan 12 18:22:50 2014 sebastien
*/

#include "wolf.h"

int	my_strcmp(char *s1, char *s2)
{
  return ((*s1 == *s2 && *s1) ? (my_strcmp(++s1, ++s2)) : (*s1 - *s2));
}

int	is_usage(int argc, char *str)
{
  if (argc == 1 || my_strcmp(str, "--help") == 0)
  {
    my_putstr("usage: ./wolf3d [--help] map\n\n");
    my_putstr("\t--help  print this message\n\n");
    my_putstr("\tArrow up    -> move up\n");
    my_putstr("\tArrow down  -> move down\n");
    my_putstr("\tArrow left  -> turn left\n");
    my_putstr("\tArrow right -> turn right\n");
    return (1);
  }
  return (0);
}

int	is_good_map(t_infos_mlx *infos_mlx, int **map)
{
  int	i;
  int	j;
  int	max_x;
  int	is_zero;

  j = 0;
  is_zero = 0;
  max_x = infos_mlx->env->size_x;
  while (map[j])
  {
    i = 0;
    while (i < max_x)
    {
      if (map[j][i] == 0)
	is_zero += 1;
      i = i + 1;
    }
    j = j + 1;
  }
  if ((max_x < (int)X_START || infos_mlx->env->size_y < (int)Y_START)
      || map[(int)Y_START][(int)X_START] == 1)
    return (FAILED);
  return ((is_zero > 0) ? (1) : (FAILED));
}
