/*
** client_receive.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Mon Jun 26 17:39:17 2017 Elodie
** Last update Sun Jul  2 22:10:42 2017 Elodie
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

void        cmd_broadcast(t_server *serv, t_cmd *cmd, int fd)
{
    (void)cmd;
    (void)serv;
    (void)fd;
    printf("BROADCAST\n");
}

void        cmd_eject(t_server *serv, t_cmd *cmd, int fd)
{
  fct     move[4];
  int		from[2];
  t_client	*tmp;
  (void)cmd;

  tmp = find_client(serv, fd);
  from[0] = tmp->p->turn;
  from[1] = 0;
  move[0] = &move_up;
  move[1] = &move_right;
  move[2] = &move_down;
  move[3] = &move_left;
  eject_players(serv, move, tmp, from);
}

void        cmd_forward(t_server *serv, t_cmd *cmd, int fd)
{
    t_client	*tmp;
    char	forw[128];
    fct     forward[4];
    (void)cmd;

    forward[0] = &move_up;
    forward[1] = &move_right;
    forward[2] = &move_down;
    forward[3] = &move_left;
    tmp = find_client(serv, fd);
    forward[tmp->p->turn](serv, fd);
    sprintf(forw, "ppo %d %d %d %d", tmp->id, tmp->p->positions.y,
	    tmp->p->positions.x, tmp->p->turn);
    print_graph(serv, forw);
}

void        cmd_inventory(t_server *serv, t_cmd *cmd, int fd)
{
    (void)cmd;
    t_client	*tmp;

    tmp = find_client(serv, fd);
    dprintf(fd, "[ food %d, linemate %d, deraumere %d, sibur %d, ",
	    tmp->p->inventory->bag[FOOD],
	    tmp->p->inventory->bag[LINEMATE],
	    tmp->p->inventory->bag[DERAUMERE],
	    tmp->p->inventory->bag[SIBUR]);
    dprintf(fd, "mendiane %d, phiras %d, thystame %d ]\n",
	    tmp->p->inventory->bag[MENDIANE],
	    tmp->p->inventory->bag[PHIRAS],
	    tmp->p->inventory->bag[THYSTAME]);
}

void        cmd_set(t_server *serv, t_cmd *cmd, int fd)
{
  (void)cmd;
  char          *type;
  int           stone;
  int           x;
  int           y;
  t_client      *tmp;

  tmp = find_client(serv, fd);
  x = tmp->p->positions.x;
  y = tmp->p->positions.y;
  type = strdup(cmd->arg[0]);
  if ((stone = get_stone_index(type)) == -1)
    dprintf(fd, "ko\n");
  else if (tmp->p->inventory->bag[stone] > 0)
    {
      tmp->p->inventory->pop(tmp->p->inventory, stone, 1);
      serv->world[y][x].inv->push(serv->world[y][x].inv, stone, 1);
      dprintf(fd, "ok\n");
      print_take_set_graph(serv, tmp, stone);
    }
  else
    dprintf(fd, "ko\n");
}
