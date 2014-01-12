/*
** event_key.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Fri Jan 10 21:15:43 2014 sebastien
** Last update Sun Jan 12 14:39:48 2014 sebastien
*/

#include <stdlib.h>
#include "wolf.h"

void	my_exit(t_infos_mlx *infos_mlx)
{
  free_map(infos_mlx->env->map);
  free_func(infos_mlx->env->list_func);
  free(infos_mlx->env);
  free(infos_mlx);
  exit(42);
}

void	head_left(t_infos_mlx *infos_mlx)
{
  infos_mlx->env->angle = infos_mlx->env->angle
    + GET_ROT(infos_mlx->env->rot_speed);
  (infos_mlx->env->angle == 360) ? (infos_mlx->env->angle = 0) : (0);
  disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	head_right(t_infos_mlx *infos_mlx)
{
  infos_mlx->env->angle = infos_mlx->env->angle
    - GET_ROT(infos_mlx->env->rot_speed);
  (infos_mlx->env->angle < 0) ? (infos_mlx->env->angle = 359) : (0);
  disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	move_up(t_infos_mlx *infos_mlx)
{
  float	tmp_x;
  float	tmp_y;
  float	speed;

  speed = GET_WALK(infos_mlx->env->walk_speed);
  tmp_x = infos_mlx->env->x + speed * cos(RAD(infos_mlx->env->angle));
  tmp_y = infos_mlx->env->y + speed * sin(RAD(infos_mlx->env->angle));
  if (infos_mlx->env->map[(int)tmp_y][(int)tmp_x] == 1)
    return ;
  else
  {
    infos_mlx->env->x = tmp_x;
    infos_mlx->env->y = tmp_y;
    disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
    manage_expose(infos_mlx);
  }
}

void	move_down(t_infos_mlx *infos_mlx)
{
  float	tmp_x;
  float	tmp_y;
  float	speed;

  speed = GET_WALK(infos_mlx->env->walk_speed);
  tmp_x = infos_mlx->env->x - speed * cos(RAD(infos_mlx->env->angle));
  tmp_y = infos_mlx->env->y - speed * sin(RAD(infos_mlx->env->angle));
  if (infos_mlx->env->map[(int)tmp_y][(int)tmp_x] == 1)
    return ;
  else
  {
    infos_mlx->env->x = tmp_x;
    infos_mlx->env->y = tmp_y;
    disp_img(infos_mlx, infos_mlx->env->map, infos_mlx->env);
    manage_expose(infos_mlx);
  }
}
