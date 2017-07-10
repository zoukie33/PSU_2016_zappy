/*
** incantation_2.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Wed Jun 28 11:49:59 2017 Elodie
** Last update Sun Jul  2 13:25:31 2017 Elodie
*/

#include "server.h"

void        elevation_six(t_server *serv, t_client *client, int fd)
{
  int           x;
  int           y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
    if (check_players_nbr(serv, client, 6) == true)
    {
      if (check_elevation_6(serv, x, y) == true)
	{
	  client->p->lvl += 1;
	  dprintf(fd, "ok\n");
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  empty_tile(serv, x, y);
	  return ;
	}
    }
  sprintf(lvl, "pie %d %d 6\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}

void        elevation_seven(t_server *serv, t_client *client, int fd)
{
  int           x;
  int           y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
  if (check_players_nbr(serv, client, 6) == true)
    {
      if (check_elevation_7(serv, x, y) == true)
	{
	  lvl_up(serv, x, y);
	  empty_tile(serv, x, y);
	  dprintf(fd, "ok\n");
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  end_incantation(serv, x, y);
	  return ;
	}
    }
  sprintf(lvl, "pie %d %d 7\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}
