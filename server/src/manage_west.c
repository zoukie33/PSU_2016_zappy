/*
** manage_west.c for manage_west in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy/src/cmd_IA
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 16:07:52 2017 zoukie
** Last update Sun Jul  2 22:00:02 2017 Elodie
*/

#include "server.h"

void	manage_West(t_server *serv, int fd, int move_x, int move_y)
{
  int	i;
  int	inventory;
  int	inc;
  int	delim_y;
  t_client	*tmp;

  inventory = 0;
  tmp = find_client(serv, fd);
  for (i = 1 ; i != tmp->p->lvl + 1 ; i++)
    {
      move_y = move_y - 1;
      move_y = manage_pos_y(move_y, serv);
      move_x = move_x - 1;
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
      delim_y = inc = inventory = 0;
    }
}

void	look_West(t_server *serv, int fd)
{
  t_client	*tmp;
  int	move_x;
  int	move_y;

  tmp = find_client(serv, fd);
  move_y = tmp->p->positions.y;
  move_x = tmp->p->positions.x;
  dprintf(fd, "[");
  print_bag(serv, fd, 0);
  manage_West(serv, fd, move_x, move_y);
  dprintf(fd, "]\n");
}
