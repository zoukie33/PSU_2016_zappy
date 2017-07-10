/*
** eject.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Wed Jun 28 17:16:01 2017 Elodie
** Last update Sun Jul  2 22:11:24 2017 Elodie
*/

#include <string.h>
#include "server.h"

int     find_orientation(t_client *client, orientation turn)
{
  int	or;

  or = client->p->turn - turn;
  if (or == 0)
    or = turn;
  else if (or == -1)
    or = or + 2;
  else if (or == -2)
    or = or + 2;
  else if (or == -3)
    or = or + 2;
  if (or == -1)
    or = 1;
  else if (or == -2)
    or = 2;
  client->p->turn = turn;
  return (or);
}

static bool		check_if(t_client *cli, t_client *tmp)
{
  if (tmp->p->positions.x == cli->p->positions.x &&
      tmp->p->positions.y == cli->p->positions.y && tmp->fd != cli->fd)
    return (true);
  return (false);
}

static void	end_if(t_client *tmp, t_server *serv, char player[])
{
  sprintf(player, "ppo %d %d %d %d", tmp->id, tmp->p->positions.y,
	  tmp->p->positions.x, tmp->p->turn);
  print_graph(serv, player);
}

void	eject_players(t_server *serv, fct move[], t_client *cli, int turns[])
{
  int		i;
  t_client	*tmp;
  char		eject[128];
  char		player[128];
  bool		pr;

  i = -1;
  pr = false;
  while (++i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head ; tmp != NULL ; tmp = tmp->next)
	{
	  if (check_if(cli, tmp) == true)
	    {
	      turns[1] = find_orientation(cli, turns[0]);
	      dprintf(tmp->fd, "eject: %d\n", turns[1]);
	      move[tmp->p->turn](serv, tmp->fd);
	      sprintf(eject, "pex %d", cli->id);
	      if (pr == false)
		print_graph(serv, eject);
	      pr = true;
	      end_if(tmp, serv, player);
	    }
	}
    }
}
