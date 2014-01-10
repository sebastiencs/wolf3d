/*
** find_wall.c for w3f in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Fri Jan 10 19:01:52 2014 sebastien
** Last update Fri Jan 10 20:12:20 2014 sebastien
*/

#include <X11/X.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "wolf.h"

float	find_x(t_env *env , int **map, float x1, float y1)
{
  float	k;
  int	new_x;
  int	new_y;
  int	i;
  float	little;

  i = 0;
  little = WALL_NO_FOUND;
  while (i < env->size_x)
  {
    k = ((i - env->x) / x1);
    new_x = i;
    new_y = env->y + (k * y1);
    if (new_x != 0)
    {
      new_x = new_x - 1;
      if (new_x >= (int)env->x)
	new_x = new_x + 1;
    }
    if (k >= 0 && k < little && new_x < env->size_x && new_x >= 0 &&
	new_y >= 0 && new_y < env->size_y && map[new_y][new_x] == 1)
      little = k;
    i = i + 1;
  }
  return (little);
}

float	find_y(t_env *env , int **map, float x1, float y1)
{
  float	k;
  int	new_x;
  int	new_y;
  int	i;
  float	little;

  i = 0;
  little = WALL_NO_FOUND;
  while (i < env->size_y)
  {
    k = ((i - env->y) / y1);
    new_x = env->x + (k * x1);
    new_y = i;
    if (new_y != 0)
    {
      new_y = new_y - 1;
      if (new_y >= (int)env->y)
	new_y = new_y + 1;
    }
    if (k >= 0 && k < little && new_x < env->size_x && new_y < env->size_y
	&& new_y >= 0 && new_x >= 0 && (int)k >= 0 && map[new_y][new_x] == 1)
      little = k;
    i = i + 1;
  }
  return (little);
}

float	find_wall(t_env *env , int **map, float each_x, unsigned int *color)
{
  float	x1;
  float	y1;
  float	k_x;
  float	k_y;
  float	tmp;

  x1 = env->x + 0.5;
  y1 = env->y + each_x;
  tmp = x1;
  x1 = cos(RAD(env->angle)) * (tmp - env->x) - sin(RAD(env->angle)) * (y1 - env->y);
  y1 = sin(RAD(env->angle)) * (tmp - env->x) + cos(RAD(env->angle)) * (y1 - env->y);
  k_x = find_x(env, map, x1, y1);
  k_y = find_y(env, map, x1, y1);
  *color = 0;
  (x1 > 0) ? (*color = 0x33CCCC) : (*color = 0x3333CC);
  (k_x > k_y) ? ((y1 > 0) ? (*color = 0x990033) : (*color = 0xCC6666)) : (0);
  if (k_x > k_y)
    return (k_y);
  return (k_x);
}
