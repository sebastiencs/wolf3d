/*
** utils.c for w3d in /home/sebastien/travaux/Wolf3d
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Dec 22 12:56:00 2013 Sebastien Chapuis
** Last update Fri Jan 10 23:11:26 2014 sebastien
*/

#include <unistd.h>

int		my_puterror(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    write(2, &str[i++], 1);
  return (-1);
}

void		my_putstr(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(1, &str[i++], 1);
}

unsigned int	my_strlen(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i = i + 1;
  return (i);
}

void	swap_int(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int	val_abs(int nb)
{
  if (nb < 0)
    return (-nb);
  return (nb);
}
