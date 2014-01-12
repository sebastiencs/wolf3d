/*
** fdf.h for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Dec 22 12:33:22 2013 Sebastien Chapuis
** Last update Sun Jan 12 15:02:14 2014 sebastien
*/

#ifndef WOLF_H_
# define WOLF_H_

# include <math.h>

typedef struct		s_line
{
  int			x1;
  int			x2;
  int			y1;
  int			y2;
}			t_line;

typedef struct		s_env
{
  float			x;
  float			y;
  float			angle;
  int			head;
  int			rot_speed;
  int			walk_speed;
  int			size_x;
  int			size_y;
  int			**map;
  struct s_functions	*list_func;
}			t_env;

typedef struct		s_infos_mlx
{
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
  t_env			*env;
}			t_infos_mlx;

typedef struct		s_functions
{
  int			keycode;
  void			(*func_ptr)(t_infos_mlx *infos_mlx);
  struct s_functions	*next;
}			t_functions;

typedef struct		s_map
{
  int			line;
  char			*str;
  struct s_map		*next;
}			t_map;

# define HEIGHT		(600)
# define WIDTH		(800)
# define WALL_NO_FOUND	(1000000)
# define KEYPRESSMASK	(1)
# define KEYPRESS	(2)
# define WINDOW_TITLE	"WOLF3D"
# define ALLOC_ERROR	"error: could not alloc\n"
# define MLX_ERROR	"error: could not open window\n"
# define FILE_ERROR	"error: could not open file\n"
# define MAP_ERROR	"error: map error !\n"
# define COLOR_STRINGS	(0xFFFFFF)
# define FIRST_COLOR	(0x33CCCC)
# define SECOND_COLOR	(0x3333CC)
# define THIRD_COLOR	(0x990033)
# define FOURTH_COLOR	(0xCC6666)
# define SKY_COLOR	(0x9900FF)
# define FLOOR_COLOR	(0x777777)
# define ANGLE_START	(0)
# define X_START	(2.25)
# define Y_START	(2.25)
# define HEAD_START	(0)
# define ROT_START	(20)
# define WALK_START	(1)
# define FAILED		(-1)
# define RAD(x)		(x * (M_PI / 180))
# define GET_ROT(x)	((x) / 10.0)
# define GET_WALK(x)	((x) / 10.0)

int		manage_expose(void *param);
int		manage_key(int keycode, t_infos_mlx *infos_mlx);
int		transform_coord(t_line *c);
void		swap_int(int *a, int *b);
int		val_abs(int nb);
void		disp_img(t_infos_mlx *infos_mlx, int **map, t_env *env);
t_line		get_coord(int x1, int y1, int x2, int y2);
char		*get_next_line(const int fd);
int		**get_map(char *filename, t_env *env);
int		push_map(t_map **map, char *str, int line);
int		check_line(char *str);
unsigned int	my_strlen(char *str);
int		my_puterror(char *str);
float		find_wall(t_env *env, int **map, float each_x,
			  unsigned int *color);
void		free_list(t_map *list);
t_functions	*init_func(void);
void		my_exit(t_infos_mlx *infos_mlx);
void		head_left(t_infos_mlx *infos_mlx);
void		head_right(t_infos_mlx *infos_mlx);
void		move_up(t_infos_mlx *infos_mlx);
void		move_down(t_infos_mlx *infos_mlx);
void		head_up(t_infos_mlx *infos_mlx);
void		head_down(t_infos_mlx *infos_mlx);
void		more_rot(t_infos_mlx *infos_mlx);
void		less_rot(t_infos_mlx *infos_mlx);
void		speed_up(t_infos_mlx *infos_mlx);
void		speed_down(t_infos_mlx *infos_mlx);
void		head_restore(t_infos_mlx *infos_mlx);
void		print_line(t_line c, t_infos_mlx *infos_mlx,
			   unsigned int color);
void		free_structs(int **map);
void		free_map(int **map);
void		free_func(t_functions *list);
int		is_usage(int argc, char *str);
int		is_good_map(t_infos_mlx *infos_mlx, int **map);

#endif /* !WOLF_H_ */
