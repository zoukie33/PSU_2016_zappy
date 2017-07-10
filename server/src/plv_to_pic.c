/*
** plv_to_pic.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/srv/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Mon Jun 12 17:10:59 2017 Elodie
** Last update Sun Jul  2 22:09:52 2017 Elodie
*/

#include <stdlib.h>
#include "server.h"

static int	ppo_client(t_server *serv, int id_client, int fd_graph)
{
  int		i;
  t_client	*tmp;

  i = 0;
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head ; tmp != NULL ; tmp = tmp->next)
	{
	  if (tmp->id == id_client)
	    {
	      dprintf(fd_graph, "%d %d %d %d\n", id_client, tmp->p->positions.y,
		      tmp->p->positions.x,
		      tmp->p->turn);
	      return (0);
	    }
	}
      i++;
    }
  return (0);
}

void        cmd_ppo(t_server *serv, t_cmd *cmd, int fd)
{
    int		id_client;
    t_client	*tmp;

    id_client = atoi(cmd->arg[0]);
    for (tmp = serv->graph->head ; tmp != NULL ; tmp = tmp->next)
      {
	if (tmp->fd == fd)
	  ppo_client(serv, id_client, fd);
      }
}

void		cmd_plv(t_server *serv, t_cmd *cmd, int fd)
{
  t_client	*cli;
  int		id_player;
  int		i;
  (void)cmd;

  i = 0;
  id_player = atoi(cmd->arg[0]);
  while (i < serv->args->nb_team)
    {
      for (cli = serv->teams[i].clients->head; cli != NULL; cli = cli->next)
	{
	  if (cli->id == id_player)
	    dprintf(fd, "plv %d %d\n", cli->id, cli->p->lvl);
	}
      i++;
    }
}

void		cmd_pin(t_server *serv, t_cmd *cmd, int fd)
{
  t_client	*cli;
  int		id_player;
  int		i;

  id_player = atoi(cmd->arg[0]);
  i = 0;
  while (i < serv->args->nb_team)
    {
      for (cli = serv->teams[i].clients->head; cli != NULL; cli = cli->next)
	{
	  if (cli->id == id_player)
	    dprintf(fd, "pin %d %d %d %d %d %d %d %d %d %d %d\n",
		    id_player, cli->p->positions.y,
		    cli->p->positions.x, cli->p->inventory->bag[0],
		    cli->p->inventory->bag[1],
		    cli->p->inventory->bag[1],
		    cli->p->inventory->bag[2],
		    cli->p->inventory->bag[3],
		    cli->p->inventory->bag[4],
		    cli->p->inventory->bag[5],
		    cli->p->inventory->bag[6]);
	}
      i++;
    }
}
