/*
** world.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/srv/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Mon Jun 12 17:12:50 2017 Elodie
** Last update Sun Jul  2 14:02:53 2017 Elodie
*/

#include <time.h>
#include <stdlib.h>
#include "server.h"

static int		world_positions(t_world **world, int x, int y)
{
  int		i;
  int		j;
  int		s;
  (void)x;

  i = 0;
  j = 0;
  s = 0;
  while (i < y)
    {
        while (j < x)
          {
            world[i][j].pos.x = j;
            world[i][j].pos.y = s;
            j++;
          }
        j = 0;
        s++;
	i++;
    }
  return (0);
}

void	print_world(t_world **world, int fd, int x, int y)
{
  int		i;
  int		j;
  int		c;

  i = 0;
  j = 0;
  c = 0;
  while (i < y)
    {
      while (j < x)
	{
	  dprintf(fd, "bct %d %d ", world[i][j].pos.y, world[i][j].pos.x);
	  while (c < 7)
	    {
	      dprintf(fd, "%d ", world[i]->inv->bag[c]);
	      c++;
	    }
	  dprintf(fd, "\n");
	  c = 0;
	  j++;
	}
      j = 0;
      i++;
    }
}

static	void	init_stones(t_world **world, int x, int y)
{
  int		i;
  int		j;
  int		s;
  int		rd;

  i = -1;
  j = 0;
  s = 0;
  while (++i < y)
    {
      while (j < x)
	{
	  if ((world[i][j].inv = construct_inventory()) == NULL)
	    printf("inv cons fail\n");
	  while (s < 7)
	    {
	      rd = rand() % 10;
	      world[i][j].inv->bag[s] = rd;
	      s++;
	    }
	  s = 0;
	  j++;
	}
      j = 0;
    }
}

static void init_players(t_world **world, t_server *serv)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < serv->args->dim.y)
    {
      while (j < serv->args->dim.x)
        {
          world[i][j].players = 0;
          j++;
        }
      j = 0;
      i++;
    }
}

int		init_world(t_server *server)
{
  t_world	**world;
  int		i;

  i = 0;
  printf("INITIALIZING WORLD...\n");
  if ((world = malloc(sizeof(t_world *) * (server->args->dim.y + 1))) == NULL)
    return (-1);
  while (i < server->args->dim.y)
    {
        if ((world[i] = malloc(sizeof(t_world) * server->args->dim.x)) == NULL)
	      return (-1);
      i++;
    }
  world[i] = NULL;
  world_positions(world, server->args->dim.x, server->args->dim.y);
  init_stones(world, server->args->dim.x, server->args->dim.y);
  init_players(world, server);
  server->world = world;
  return (0);
}
