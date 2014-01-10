/*
** event_key.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Fri Jan 10 21:15:43 2014 sebastien
** Last update Sat Jan 11 00:41:50 2014 sebastien
*/

#include <stdlib.h>
#include "wolf.h"

void    my_exit(t_infos_mlx *infos_mlx)
{
  exit(42);
}

void	head_left(t_infos_mlx *infos_mlx)
{
  infos_mlx->env->angle = infos_mlx->env->angle + 2.0;
  (infos_mlx->env->angle == 360) ? (infos_mlx->env->angle = 0) : (0);
  disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	head_right(t_infos_mlx *infos_mlx)
{
  infos_mlx->env->angle = infos_mlx->env->angle - 2.0;
  (infos_mlx->env->angle < 0) ? (infos_mlx->env->angle = 359) : (0);
  disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	move_up(t_infos_mlx *infos_mlx)
{
  float	tmp_x;
  float	tmp_y;

  tmp_x = infos_mlx->env->x + 0.1 * cos(RAD(infos_mlx->env->angle));
  tmp_y = infos_mlx->env->y + 0.1 * sin(RAD(infos_mlx->env->angle));
  if (infos_mlx->env->map[(int)tmp_y][(int)tmp_x] == 1)
    return ;
  else
  {
    infos_mlx->env->x = tmp_x;
    infos_mlx->env->y = tmp_y;
    disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
    manage_expose(infos_mlx);
  }
}

void	move_down(t_infos_mlx *infos_mlx)
{
  float	tmp_x;
  float	tmp_y;

  tmp_x = infos_mlx->env->x - 0.1 * cos(RAD(infos_mlx->env->angle));
  tmp_y = infos_mlx->env->y - 0.1 * sin(RAD(infos_mlx->env->angle));
  if (infos_mlx->env->map[(int)tmp_y][(int)tmp_x] == 1)
    return ;
  else
  {
    infos_mlx->env->x = tmp_x;
    infos_mlx->env->y = tmp_y;
    disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
    manage_expose(infos_mlx);
  }
}
