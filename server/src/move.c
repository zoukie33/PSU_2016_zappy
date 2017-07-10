/*
** move.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Tue Jun 27 15:39:16 2017 Elodie
** Last update Sun Jul  2 16:07:37 2017 Elodie
*/

#include "server.h"

void        move_up(t_server *server, int fd)
{
  printf("UP\n");
  int     x;
  int     y;
  t_client	*tmp;

  tmp = find_client(server, fd);
  x = tmp->p->positions.x;
  y = tmp->p->positions.y;
  server->world[y][x].players--;
  if (tmp->p->positions.y == server->args->dim.y - 1)
    tmp->p->positions.y = 0;
  else
    tmp->p->positions.y++;
  server->world[y][x].players++;
  dprintf(fd, "ok\n");
}

void        move_down(t_server *server, int fd)
{
    int		x;
    int		y;
    t_client	*tmp;

    tmp = find_client(server, fd);
    x = tmp->p->positions.x;
    y = tmp->p->positions.y;
    server->world[y][x].players--;
    if (tmp->p->positions.y == 0)
      tmp->p->positions.y = server->args->dim.y - 1;
    else
      tmp->p->positions.y--;
    server->world[y][x].players++;
    dprintf(fd, "ok\n");
}

void        move_left(t_server *server, int fd)
{
  printf("LEFT\n");
  int     x;
    int     y;
    t_client	*tmp;

    tmp = find_client(server, fd);
    x = tmp->p->positions.x;
    y = tmp->p->positions.y;
    server->world[y][x].players--;
    if (tmp->p->positions.x == 0)
      tmp->p->positions.x = server->args->dim.x - 1;
    else
      tmp->p->positions.x--;
    server->world[y][x].players++;
    dprintf(fd, "ok\n");
    return ;
}

void        move_right(t_server *server, int fd)
{
    printf("RIGHT\n");
    int     x;
    int     y;
    t_client	*tmp;

    tmp = find_client(server, fd);
    x = tmp->p->positions.x;
    y = tmp->p->positions.y;
    server->world[y][x].players--;
    if (tmp->p->positions.x == server->args->dim.x - 1)
      tmp->p->positions.x = 0;
    else
      tmp->p->positions.x++;
    server->world[y][x].players++;
    dprintf(fd, "ok\n");
    return ;
}
