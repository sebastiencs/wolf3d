/*
** events.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Dec 22 12:38:20 2013 Sebastien Chapuis
** Last update Sat Jan 11 00:42:27 2014 sebastien
*/

#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include "mlx.h"
#include "wolf.h"

int		manage_expose(void *param)
{
  t_infos_mlx   *infos_mlx;

  infos_mlx = param;
  mlx_put_image_to_window(infos_mlx->mlx_ptr,
                          infos_mlx->win_ptr,
                          infos_mlx->img, 0, 0);
  return (0);
}

int             manage_key(int keycode, t_infos_mlx *infos_mlx)
{
  do_func(keycode, infos_mlx->env->list_func, infos_mlx);
  return (0);
}

int	transform_coord(t_line *c)
{
  if (c->x1 == c->x2 && c->y1 == c->y2)
    return (-1);
  (c->x1 > c->x2) ? (swap_int(&(c->y1), &(c->y2))) : (0);
  (c->x1 > c->x2) ? (swap_int(&(c->x1), &(c->x2))) : (0);
  return (0);
}
