/*
** take.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Fri Jun 30 15:02:31 2017 Elodie
** Last update Sun Jul  2 22:12:35 2017 Elodie
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

int         get_stone_index(char *stone)
{
    char    **stones;
    int     i;

    if ((stones = malloc(sizeof(char *) * 9)) == NULL)
        return (-1);
    stones[0] = strdup("food");
    stones[1] = strdup("linemate");
    stones[2] = strdup("deraumere");
    stones[3] = strdup("sibur");
    stones[4] = strdup("mendiane");
    stones[5] = strdup("phiras");
    stones[6] = strdup("thystame");
    stones[7] = NULL;
    for (i = 0; i < 7 ; i++)
    {
        if (strcmp(stones[i], stone) == 0)
            return (i);
    }
    return (-1);
}

void		print_take_set_graph(t_server *serv, t_client *client,
				     int stone)
{
  char		take[128];
  char		inv[128];
  char		world[128];
  int		x;
  int		y;

  x = client->p->positions.x;
  y = client->p->positions.y;
  sprintf(take, "pgt %d %d", client->id, stone);
  sprintf(inv, "pin %d %d %d %d %d %d %d %d %d %d",
	  client->id, y, x, client->p->inventory->bag[0],
	  client->p->inventory->bag[1], client->p->inventory->bag[2],
	  client->p->inventory->bag[3], client->p->inventory->bag[4],
	  client->p->inventory->bag[5], client->p->inventory->bag[6]);
  sprintf(world, "bct %d %d %d %d %d %d %d %d %d",
	  y, x, serv->world[y][x].inv->bag[0],
	  serv->world[y][x].inv->bag[1], serv->world[y][x].inv->bag[2],
	  serv->world[y][x].inv->bag[3], serv->world[y][x].inv->bag[4],
	  serv->world[y][x].inv->bag[5], serv->world[y][x].inv->bag[6]);
  sprintf(take, "pgt %d %d", client->id, stone);
  print_graph(serv, take);
  print_graph(serv, inv);
  print_graph(serv, world);
}
