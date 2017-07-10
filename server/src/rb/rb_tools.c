/*
** rb_tools.c for  in /home/beche/rb
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Mon Jun 26 09:26:48 2017 beche
** Last update Sun Jul  2 10:49:15 2017 beche
*/

#include "rb.h"

int	get_index(char	*buff, char *write)
{
  int	index;

  index = sizeof(buff) + sizeof(write);
  return (index);
}

int	get_cmd_len(t_rb *rb)
{
  int	i;
  int	n;

  n = 0;
  i = rb->read;
  while (rb->buff[i] != '\n')
    {
      if (i >= (RB_SIZE - 1))
	i = 0;
      else
	i++;
      n++;
    }
  return (n);
}

char	*get_cmd_string(t_rb *rb, int i, char *str)
{
  int	k;

  k = 0;
  while (rb->buff[i] != '\n')
    {
      str[k++] = rb->buff[i];
      if (i >= (RB_SIZE - 1))
	{
	  i = 0;
	  rb->read = 0;
	}
      else
	{
	  rb->read++;
	  i++;
	}
    }
  str[k] = 0;
  return (str);
}
