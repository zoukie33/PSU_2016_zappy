/*
** incantation.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Wed Jun 28 11:48:24 2017 Elodie
** Last update Sun Jul  2 13:28:32 2017 Elodie
*/

#include "server.h"

void        elevation_one(t_server *serv, t_client *client, int fd)
{
  int		x;
  int		y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
  if (check_players_nbr(serv, client, 1) == true)
    {
      if (check_elevation_1(serv, x, y) == true)
        {
	  lvl_up(serv, x, y);
	  dprintf(fd, "ok\n");
	  end_incantation(serv, x, y);
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  empty_tile(serv, x, y);
	  return ;
        }
    }
  sprintf(lvl, "pie %d %d 1\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}

void        elevation_two(t_server *serv, t_client *client, int fd)
{
  int		x;
  int		y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
  if (check_players_nbr(serv, client, 2) == true)
    {
      if (check_elevation_2(serv, x, y) == true)
        {
	  lvl_up(serv, x, y);
	  dprintf(fd, "ok\n");
	  end_incantation(serv, x, y);
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  empty_tile(serv, x, y);
	  return ;
        }
    }
  sprintf(lvl, "pie %d %d 2\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}

void        elevation_three(t_server *serv, t_client *client, int fd)
{
  int		x;
  int		y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;

  if (check_players_nbr(serv, client, 2) == true)
    {
      if (check_elevation_3(serv, x, y) == true)
        {
	  lvl_up(serv, x, y);
	  dprintf(fd, "ok\n");
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  end_incantation(serv, x, y);
	  empty_tile(serv, x, y);
	  return ;
        }
    }
  sprintf(lvl, "pie %d %d 3\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}

void        elevation_four(t_server *serv, t_client *client, int fd)
{
  int		x;
  int		y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
  if (check_players_nbr(serv, client, 4) == true)
    {
      if (check_elevation_4(serv, x, y) == true)
        {
	  lvl_up(serv, x, y);
	  dprintf(fd, "ok\n");
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  end_incantation(serv, x, y);
	  empty_tile(serv, x, y);
	  return ;
        }
    }
  sprintf(lvl, "pie %d %d 4\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}

void        elevation_five(t_server *serv, t_client *client, int fd)
{
  int		x;
  int		y;
  char		lvl[128];

  x = client->p->positions.x;
  y = client->p->positions.y;
  if (check_players_nbr(serv, client, 4) == true)
    {
      if (check_elevation_5(serv, x, y) == true)
        {
	  lvl_up(serv, x, y);
	  dprintf(fd, "ok\n");
	  sprintf(lvl, "pie %d %d %d\n", y, x, client->p->lvl);
	  print_graph(serv, lvl);
	  end_incantation(serv, x, y);
	  empty_tile(serv, x, y);
	  return ;
        }
    }
  sprintf(lvl, "pie %d %d 5\n", y, x);
  print_graph(serv, lvl);
  end_incantation(serv, x, y);
  dprintf(fd, "ko\n");
}
