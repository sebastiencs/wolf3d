
/*
** main.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Dec 22 12:31:56 2013 Sebastien Chapuis
** Last update Sat Jan 11 00:42:02 2014 sebastien
*/

#include <X11/X.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "wolf.h"

#include <stdio.h>

int	init_infos_mlx(t_infos_mlx **infos_mlx)
{
  if (((*infos_mlx)->mlx_ptr = mlx_init()) == NULL)
    return (my_puterror("error: can't open window\n"));
  if (((*infos_mlx)->win_ptr = mlx_new_window((*infos_mlx)->mlx_ptr,
					      WIDTH, HEIGHT,
					      "WOLF3d")) == NULL)
    return (my_puterror("error: can't open window\n"));
  if (((*infos_mlx)->img = mlx_new_image((*infos_mlx)->mlx_ptr,
					 WIDTH, HEIGHT)) == NULL)
    return (my_puterror("error: can't open window\n"));
  (*infos_mlx)->data = mlx_get_data_addr((*infos_mlx)->img,
				      &((*infos_mlx)->bpp),
				      &((*infos_mlx)->sizeline),
				      &((*infos_mlx)->endian));
  return (0);
}

void		disp_rectangle(t_infos_mlx *infos_mlx, int **map, t_env *env)
{
  unsigned int	color;
  int		x;
  float		dist_wall;
  float		each_x;

  x = 0;
  each_x = 0.5;
  while (x < WIDTH)
  {
    dist_wall = find_wall(env, map, each_x, &color);
    if (dist_wall < 0.5)
      dist_wall = 0.5;
    print_line(get_coord(x, 0, x, (HEIGHT / 2) - (HEIGHT / (2 * dist_wall))
			 + env->head), infos_mlx, 0x9900FF);
    print_line(get_coord(x, (HEIGHT / 2) - (HEIGHT / (2 * dist_wall))
			 + env->head, x, (HEIGHT / 2)
			 + (HEIGHT / (2 * dist_wall)) + env->head),
	       infos_mlx, color);
    print_line(get_coord(x, (HEIGHT / 2) + (HEIGHT / (2 * dist_wall)
					    + env->head), x, HEIGHT),
	       infos_mlx, 0x777777);
    x = x + 1;
    each_x = each_x - (1.0 / (float)WIDTH);
  }
}

int		main(int argc, char **argv)
{
  t_infos_mlx	*infos_mlx;

  (void)argc;
  if ((((infos_mlx = (t_infos_mlx*)malloc(sizeof(t_infos_mlx))) == NULL)
      || (infos_mlx->env = (t_env*)malloc(sizeof(t_env))) == NULL)
      || (infos_mlx->env->list_func = init_func()) == NULL)
    return (-1);
  if ((init_infos_mlx(&infos_mlx)) == -1)
    return (-1);
  if ((infos_mlx->env->map = get_map(argv[1], infos_mlx->env)) == NULL)
    return (-1);
  infos_mlx->env->angle = 0;
  infos_mlx->env->x = 1.2;
  infos_mlx->env->y = 1.2;
  infos_mlx->env->head = 0;
  disp_rectangle(infos_mlx, infos_mlx->env->map, infos_mlx->env);
  mlx_hook(infos_mlx->win_ptr, KeyPress, KeyPressMask, manage_key, infos_mlx);
  mlx_expose_hook(infos_mlx->win_ptr, manage_expose, infos_mlx);
  mlx_loop(infos_mlx->mlx_ptr);
  return (0);
}

/* float	find_wall(t_env *env , int **map, float each_x) */
/* { */
/*   float	x1; */
/*   float	y1; */
/*   float	k; */
/*   float	tmp; */
/*   int	new_x; */
/*   int	new_y; */
/*   int	i; */
/*   float	little; */

/*   x1 = env->x + 0.5; */
/*   y1 = env->y + each_x; */
/*   tmp = x1; */
/*   x1 = cos(RAD(env->angle)) * (tmp - env->x) - sin(RAD(env->angle)) * (y1 - env->y); */
/*   y1 = sin(RAD(env->angle)) * (tmp - env->x) + cos(RAD(env->angle)) * (y1 - env->y); */
/*   little = WALL_NO_FOUND; */
/*   i = 0; */
/*   k = 1; */
/*   while (i < env->size_x) */
/*   { */
/*     k = ((i - env->x) / x1); */
/*     new_x = i; */
/*     new_y = env->y + (k * y1); */
/*     if (new_x != 0) */
/*     { */
/*       new_x = new_x - 1; */
/*       if (new_x >= (int)env->x) */
/* 	new_x = new_x + 1; */
/*     } */
/*     if (k >= 0 && new_x < env->size_x && new_x >= 0 && */
/* 	new_y >= 0 && new_y < env->size_y && map[new_y][new_x] == 1) */
/*     { */
/*       if (k < little) */
/*       { */
/*       	little = k; */
/*       } */
/*     } */
/*     i = i + 1; */
/*   } */
/*   i = 0; */
/*   while (i < env->size_y) */
/*   { */
/*     k = ((i - env->y) / y1); */
/*     new_x = env->x + (k * x1); */
/*     new_y = i; */
/*     if (new_y != 0) */
/*     { */
/*       new_y = new_y - 1; */
/*       if (new_y >= (int)env->y) */
/* 	new_y = new_y + 1; */
/*     } */
/*     if (new_x < env->size_x && new_y < env->size_y */
/* 	&& new_y >= 0 && new_x >= 0 && (int)k >= 0 && map[new_y][new_x] == 1) */
/*     { */
/*       if (k > 0 && k < little) */
/*       { */
/*       	little = k; */
/*       } */
/*     } */
/*     i = i + 1; */
/*   } */
/*   return (little); */
/* } */
