/*
** manage_east.c for manage_east in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy/src/cmd_IA
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 16:06:00 2017 zoukie
** Last update Sun Jul  2 21:59:35 2017 Elodie
*/

#include "server.h"

void	manage_East(t_server *serv, int fd, int move_x, int move_y)
{
  int	i;
  int	inventory;
  int	inc;
  int	delim_y;
  t_client	*tmp;

  inventory = 0;
  tmp = find_client(serv, fd);
  for (i = 1; i != tmp->p->lvl + 1; i++)
    {
      move_y = move_y - 1;
      move_y = manage_pos_y(move_y, serv);
      move_x = move_x + 1;
      move_x = manage_pos_x(move_x, serv);
      delim_y = move_y + (2 * i);
      delim_y = manage_delim(delim_y, serv);
      inc = move_y;
      while (inc <= delim_y)
	{
	  print_bag(serv, fd, inc);
	  inc++;
	  inventory = 0;
	}
      delim_y = inventory = inc = 0;
    }
}

void	look_East(t_server *serv, int fd)
{
  int	move_x;
  int	move_y;
  t_client	*tmp;

  tmp = find_client(serv, fd);
  move_y = tmp->p->positions.y;
  move_x = tmp->p->positions.x;
  dprintf(fd, "[");
  print_bag(serv, fd, 0);
  manage_East(serv, fd, move_x, move_y);
  dprintf(fd, "]\n");
}
