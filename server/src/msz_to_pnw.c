/*
** msz_to_pnw.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/srv/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Mon Jun 12 17:08:23 2017 Elodie
** Last update Sun Jul  2 20:00:45 2017 Elodie
*/

#include <stdlib.h>
#include "server.h"

void		cmd_msz(t_server *server, t_cmd *cmd, int fd)
{
    (void)cmd;
    dprintf(fd, "msz %d %d\n", server->args->dim.y, server->args->dim.x);
}

void		cmd_bct(t_server *serv, t_cmd *cmd, int fd)
{
  int		i;
  int		j;
  int		y;

  i = -1;
  j = 0;
  y = -1;
  while (++i < serv->args->dim.y)
    {
      while (++y < serv->args->dim.x)
        {
	  if (serv->world[i][y].pos.y == atoi(cmd->arg[0]) &&
              serv->world[i][y].pos.x == atoi(cmd->arg[1]))
	    {
	      dprintf(fd, "bct %d %d", atoi(cmd->arg[0]), atoi(cmd->arg[1]));
	      while (j++ < 7)
		dprintf(fd, " %d", serv->world[i][y].inv->bag[j]);
	      j = 0;
	    }
	}
      y = 0;
    }
    dprintf(fd, "\n");
}

void		cmd_mct(t_server *serv, t_cmd *cmd, int fd)
{
  (void)cmd;
  print_world(serv->world, fd, serv->args->dim.x,
	      serv->args->dim.y);
}

void		cmd_tna(t_server *s, t_cmd *cmd, int fd)
{
    int     i;

    (void)cmd;
    for (i = 0 ; i < s->args->nb_team ; i++)
        dprintf(fd, "tna %s\n", s->args->nameT[i]);
}

void		cmd_pnw(t_server *serv, t_cmd *cmd, int fd)
{
  int		i;
  t_client	*tmp;
  bool		fd_ok;

  (void)serv;
  (void)cmd;
  i = 0;
  fd_ok = false;
  while (i < serv->args->nb_team && fd_ok == false)
    {
      tmp = serv->teams[i].clients->head;
      while (tmp != NULL)
	{
	  if (tmp->fd == fd)
	    fd_ok = true;
	  tmp = tmp->next;
	}
      i++;
    }
  dprintf(fd, "Nom de l'équipe du joueur: %s\n", tmp->p->name);
}
