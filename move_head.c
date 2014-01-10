/*
** move_head.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Fri Jan 10 22:16:48 2014 sebastien
** Last update Fri Jan 10 22:56:38 2014 sebastien
*/

#include "wolf.h"

void	head_up(t_infos_mlx *infos_mlx)
{
  if (infos_mlx->env->head <= 200)
    infos_mlx->env->head = infos_mlx->env->head + 5;
  disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	head_down(t_infos_mlx *infos_mlx)
{
  if (infos_mlx->env->head >= -200)
    infos_mlx->env->head = infos_mlx->env->head - 5;
  disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  manage_expose(infos_mlx);
}

void	head_restore(t_infos_mlx *infos_mlx)
{
  if (infos_mlx->env->head != 0)
  {
    if ((infos_mlx->env->head > 0 && infos_mlx->env->head < 25)
	|| (infos_mlx->env->head < 0 && infos_mlx->env->head > -25))
      infos_mlx->env->head = 0;
    else if (infos_mlx->env->head > 0)
      infos_mlx->env->head = infos_mlx->env->head - 25;
    else
      infos_mlx->env->head = infos_mlx->env->head + 25;
    infos_mlx->env->head = infos_mlx->env->head - 1;
    disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
    manage_expose(infos_mlx);
  }
}
