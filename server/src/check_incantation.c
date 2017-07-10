/*
** check_incantation.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Wed Jun 28 11:55:04 2017 Elodie
** Last update Sun Jul  2 17:06:51 2017 Elodie
*/

#include "server.h"

void        cmd_incantation(t_server *serv, t_cmd *cmd, int fd)
{
  (void)serv;
  (void)cmd;
  (void)fd;
  t_client      *tmp;
  fct     incantation[7];

  tmp = find_client(serv, fd);
  incantation[0] = &elevation_one;
  incantation[1] = &elevation_two;
  incantation[2] = &elevation_three;
  incantation[3] = &elevation_four;
  incantation[4] = &elevation_five;
  incantation[5] = &elevation_six;
  incantation[6] = &elevation_seven;

  incantation[tmp->p->lvl - 1](serv, tmp, fd);
}

bool         check_players_nbr(t_server *serv, t_client *client, int players)
{
    int     i;
    int     count;
    t_client	*tmp;

    count = 0;
    i = 0;
    while (i < serv->args->nb_team)
      {
	for (tmp = serv->teams[i].clients->head; tmp != NULL ; tmp = tmp->next)
	  {
	    if (tmp->p->positions.x == client->p->positions.x &&
		tmp->p->positions.y == client->p->positions.y)
	      count++;
	  }
	i++;
      }
    if (count == players)
        return (true);
    return (false);
}

void        empty_tile(t_server *serv, int x, int y)
{
    serv->world[y][x].inv->bag[1] = 0;
    serv->world[y][x].inv->bag[2] = 0;
    serv->world[y][x].inv->bag[3] = 0;
    serv->world[y][x].inv->bag[4] = 0;
    serv->world[y][x].inv->bag[5] = 0;
    serv->world[y][x].inv->bag[6] = 0;
}

void		lvl_up(t_server *serv, int x, int y)
{
  int		i;
  t_client	*tmp;

  i = 0;
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head ; tmp != NULL ; tmp = tmp->next)
	{
	  if (tmp->p->positions.x == x && tmp->p->positions.y == y)
	    tmp->p->lvl += 1;
	}
      i++;
    }
}

void		end_incantation(t_server *serv, int x, int y)
{
  int		i;
  t_client	*tmp;
  char		inc[128];

  i = 0;
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head ; tmp != NULL ; tmp = tmp->next)
	{
	  if (tmp->p->positions.x == x && tmp->p->positions.y == y)
	    {
	      sprintf(inc, "plv %d %d\n", tmp->id, tmp->p->lvl);
	      print_graph(serv, inc);
	    }
	}
      i++;
    }
}
