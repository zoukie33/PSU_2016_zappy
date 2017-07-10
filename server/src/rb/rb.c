/*
** rb.c for  in /home/beche/rb
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Mon Jun 26 08:59:54 2017 beche
** Last update Sun Jul  2 10:49:03 2017 beche
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rb.h"

static int	delete(t_rb *rb)
{
  if (rb->buff != NULL)
    free(rb->buff);
  rb->read = 0;
  rb->write = 0;
  return (0);
}

static char		*rb_read(t_rb *rb)
{
  int			i;
  char			*str;

  i = 0;
  if ((str = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  memset(str, 0, 4095);
  while (rb->read != rb->write)
    {
      if (rb->buff[rb->read] != 0)
	str[i++] = rb->buff[rb->read];
      rb->read++;
      if (rb->read >= (RB_SIZE - 1))
	{
	  rb->read = 0;
	}
    }
  return (str);
}

static int		rb_write(t_rb *rb, char *str)
{
  int		i;
  int		len;

  len = strlen(str);
  i = 0;
  if ((RB_SIZE - rb->size_to_read) < len)
    return (-1);
  for (i = 0; str[i] != 0; i++)
    {
      rb->buff[rb->write] = str[i];
      rb->write++;
      if (rb->write >= (RB_SIZE - 2))
	rb->write = 0;
    }
  rb->size_to_read += len;
  printf("size_to_read = %d --- write = %d\n", rb->size_to_read, rb->write);
  return (0);
}

static char		*rb_read_first_cmd(t_rb *rb)
{
  int	len;
  char	*str;
  int	i;

  i = rb->read;
  len = get_cmd_len(rb);
  if ((str = malloc(sizeof(char) * len + 2)) == NULL)
    return (NULL);
  memset(str, 0, len + 2);
  str = get_cmd_string(rb, i, str);
  if (rb->buff[rb->read] == '\r')
    rb->read++;
  if (rb->buff[rb->read] == '\n')
    rb->read++;
  return (str);
}

t_rb		*construct_rb()
{
  t_rb	*rb;

  if ((rb = malloc(sizeof(t_rb))) ==  NULL)
    return (NULL);
  if ((rb->buff = malloc(sizeof(char) * RB_SIZE + 1)) == NULL)
    return (NULL);
  memset(rb->buff, 0, RB_SIZE - 1);
  rb->read = 0;
  rb->write = 0;
  rb->rb_write = rb_write;
  rb->rb_read = rb_read;
  rb->rb_read_first_cmd = rb_read_first_cmd;
  rb->size_to_read = 0;
  rb->delete = delete;
  return (rb);
}
