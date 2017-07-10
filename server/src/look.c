/*
** others.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sat Jun 24 21:54:27 2017 Elodie
** Last update Sun Jul  2 19:24:53 2017 Elodie
*/

#include <stdlib.h>
#include "server.h"

int find_positions(t_server *serv, int fd)
{
  int i;
  unsigned int size;
  t_client	*tmp;

  (void)size;
  tmp = find_client(serv, fd);
  for (i = 0 ; i < serv->args->dim.x * serv->args->dim.y ; i++)
    {
      if (serv->world[i]->pos.x == tmp->p->positions.x &&
	  serv->world[i]->pos.y == tmp->p->positions.y)
	return (i);
    }
  return (-1);
}

int  get_nbr_tiles(t_server *serv, int fd)
{
  int     i;
  int     lvl;
  int     res;
  int		stk;
  t_client	*tmp;

  i = 0;
  res =  1;
  tmp = find_client(serv, fd);
  lvl = tmp->p->lvl;
  stk = 3;
  while (i < lvl)
    {
      res += stk;
      stk += 2;
      i++;
    }
  return (res);
}

void        cmd_look(t_server *serv, t_cmd *cmd, int fd)
{
  int     pos;
  int	  size;
  t_world *tiles;

  (void)cmd;
  (void)pos;
  size = get_nbr_tiles(serv, fd);
  if ((tiles = malloc(sizeof(t_world) * (size + 1))) == NULL)
    return ;
  exec_look_fct(&tiles, serv, fd);
}
