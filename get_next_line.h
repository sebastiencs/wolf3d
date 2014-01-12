/*
** get_next_line.h for gnl in /home/chapui_s/travaux/get_next_line
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Nov 19 16:54:01 2013 chapui_s
** Last update Sat Jan 11 01:49:19 2014 sebastien
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUF_SIZE	42

typedef struct	s_fd
{
  char		*str;
  int		fd;
  struct s_fd	*next;
}		t_fd;

# define CHECK_GNL(x)   ((x == 0) ? (x) : (x - 1))

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
