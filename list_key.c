/*
** keyboard.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Fri Jan 10 20:28:26 2014 sebastien
** Last update Sat Jan 11 01:30:18 2014 sebastien
*/

#include <stdlib.h>
#include "wolf.h"

static t_functions	*create_func(int keycode,
				     void (*func_ptr)(t_infos_mlx *infos_mlx))
{
  t_functions		*new;

  new = NULL;
  if ((new = (t_functions*)malloc(sizeof(*new))))
  {
    new->keycode = keycode;
    new->func_ptr = func_ptr;
    new->next = NULL;
  }
  return (new);
}

static int	push_func(t_functions **list, int keycode,
			  void (*func_ptr)(t_infos_mlx *infos_mlx))
{
  t_functions	*tmp;

  tmp = *list;
  if (*list)
  {
    while (tmp->next)
      tmp = tmp->next;
    if ((tmp->next = create_func(keycode, func_ptr)))
      return (0);
  }
  else
    if ((*list = create_func(keycode, func_ptr)))
      return (0);
  my_puterror("error: can't alloc\n");
  return (-1);
}

static int	get_keycode(int i)
{
  int		keycode;

  keycode = -1;
  (i == 0) ? (keycode = 65307) : (0);
  (i == 1) ? (keycode = 65361) : (0);
  (i == 2) ? (keycode = 65363) : (0);
  (i == 3) ? (keycode = 65362) : (0);
  (i == 4) ? (keycode = 65364) : (0);
  (i == 5) ? (keycode = 119) : (0);
  (i == 6) ? (keycode = 115) : (0);
  (i == 7) ? (keycode = 114) : (0);
  return (keycode);
}

static void	get_func(void (**func_ptr)(t_infos_mlx *infos_mlx), int i)
{
  (i == 0) ? (*func_ptr = &my_exit) : (0);
  (i == 1) ? (*func_ptr = &head_left) : (0);
  (i == 2) ? (*func_ptr = &head_right) : (0);
  (i == 3) ? (*func_ptr = &move_up) : (0);
  (i == 4) ? (*func_ptr = &move_down) : (0);
  (i == 5) ? (*func_ptr = &head_up) : (0);
  (i == 6) ? (*func_ptr = &head_down) : (0);
  (i == 7) ? (*func_ptr = &head_restore) : (0);
}


t_functions	*init_func(void)
{
  t_functions	*list_func;
  int		i;
  int		keycode;
  void		(*func_ptr)(t_infos_mlx *infos_mlx);

  i = 0;
  list_func = NULL;
  while (i < 8)
  {
    get_func(&func_ptr, i);
    keycode = get_keycode(i);
    if ((push_func(&list_func, keycode, func_ptr)) == -1)
      return (NULL);
    i = i + 1;
  }
  return (list_func);
}
