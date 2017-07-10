/*
** manage_south.c for manage_south in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy/src/cmd_IA
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 16:04:26 2017 zoukie
** Last update Sun Jul  2 21:59:54 2017 Elodie
*/

#include "server.h"

void	manage_South(t_server *serv, int fd, int move_x, int move_y)
{
  int   i;
  int   inventory;
  int   inc;
  int   delim_x;
  t_client	*tmp;

  inventory = 0;
  tmp = find_client(serv, fd);
  for (i = 1 ; i != tmp->p->lvl + 1 ; i++)
    {
      move_y = move_y + 1;
      move_y = manage_pos_y(move_y, serv);
      move_x = move_x - 1;
      move_x = manage_pos_x(move_x, serv);
      delim_x = move_x + (2 * i);
      delim_x = manage_delim(delim_x, serv);
      inc = move_x;
      while (inc <= delim_x)
	{
	  print_bag(serv, fd, inc);
	  inc++;
	  inventory = 0;
	}
      delim_x = inventory = inc = 0;
    }
}

void    look_South(t_server *serv, int fd)
{
  int	move_x;
  int	move_y;
  t_client	*tmp;

  tmp = find_client(serv, fd);
  move_y = tmp->p->positions.y;
  move_x = tmp->p->positions.x;
  dprintf(fd, "[");
  print_bag(serv, fd, 0);
  manage_South(serv, fd, move_x, move_y);
  dprintf(fd, " ]\n");
}
