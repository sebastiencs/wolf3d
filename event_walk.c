/*
** event_walk.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Sat Jan 11 14:02:01 2014 sebastien
** Last update Sat Jan 11 16:00:40 2014 sebastien
*/

#include "wolf.h"

void	speed_up(t_infos_mlx *infos_mlx)
{
  if (infos_mlx->env->walk_speed + 1 < 6)
  {
    infos_mlx->env->walk_speed += 1;
    manage_expose(infos_mlx);
  }
}

void	speed_down(t_infos_mlx *infos_mlx)
{
  if (infos_mlx->env->walk_speed - 1 > 0)
  {
    infos_mlx->env->walk_speed -= 1;
    manage_expose(infos_mlx);
  }
}
