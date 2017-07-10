/*
** client_received2.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Mon Jun 26 17:41:47 2017 Elodie
** Last update Sun Jul  2 22:10:24 2017 Elodie
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

void        cmd_connect_nbr(t_server *serv, t_cmd *cmd, int fd)
{
    (void)cmd;
    (void)serv;
    (void)fd;
}

void        cmd_fork(t_server *serv, t_cmd *cmd, int fd)
{
    (void)serv;
    (void)cmd;
    (void)fd;
}

void        cmd_left(t_server *serv, t_cmd *cmd, int fd)
{
  char		left[128];
  t_client	*client;
  (void)cmd;

  client = find_client(serv, fd);
  if (client->p->turn == 0)
    client->p->turn = 3;
  else
    client->p->turn--;
  sprintf(left, "ppo %d %d %d %d", client->id, client->p->positions.y,
	  client->p->positions.x, client->p->turn);
  print_graph(serv, left);
  dprintf(fd, "ok\n");
}

void        cmd_right(t_server *serv, t_cmd *cmd, int fd)
{
  t_client	*client;
  char		right[128];
  (void)cmd;

  client = find_client(serv, fd);
  if (client->p->turn == 3)
    client->p->turn = 0;
  else
    client->p->turn++;
  sprintf(right, "ppo %d %d %d %d", client->id, client->p->positions.y,
	  client->p->positions.x, client->p->turn);
  print_graph(serv, right);
  dprintf(fd, "ok\n");
}

void        cmd_take(t_server *serv, t_cmd *cmd, int fd)
{
  (void)cmd;
  char		*type;
  int		stone;
  int		x;
  int		y;
  t_client	*tmp;

  tmp = find_client(serv, fd);
  x = tmp->p->positions.x;
  y = tmp->p->positions.y;
  type = strdup(cmd->arg[0]);
  if ((stone = get_stone_index(type)) == -1)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  if (serv->world[y][x].inv->bag[stone] > 0)
    {
      tmp->p->inventory->push(tmp->p->inventory, stone, 1);
      serv->world[y][x].inv->pop(serv->world[y][x].inv, stone, 1);
      dprintf(fd, "ok\n");
      print_take_set_graph(serv, tmp, stone);
    }
  else
      dprintf(fd, "ko\n");
}
