/*
** client.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jun 11 14:50:36 2017 beche
** Last update Sun Jul  2 23:22:53 2017 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <server.h>
#include <client.h>

static int	upgrade(t_server *serv, t_client *c, int type, t_cmd *cmd)
{
  if (c->fd_type == FD_GUEST && (type == FD_CLIENT || type == FD_GRAPH))
    {
      c->fd_type = type;
      if (log_client(serv, c, c->fd, cmd) == -1)
	return (-1);
    }
  return (0);
}
t_client	*construct_client(int fd, t_server *s)
{
  t_client	*c;

  if ((c = malloc(sizeof(t_client))) == NULL)
    return (NULL);
  c->p = NULL;
  c->id = fd - 4;
  c->fd = fd;
  c->fd_type = FD_GUEST;
  c->handler = handle_guest;
  c->timestamp = (double)0.0;
  (void)s;
  c->rb = construct_rb();
  c->upgrade = upgrade;
  c->launcher = construct_launcher();
  return (c);
}

int	switch_to_graph(t_server *serv, t_client *c)
{
  printf("SWICHTING TO FD_GRAPH\n");
  serv->graph->push(serv->graph, c);
  serv->guest->pop(serv->guest, c);
  FD_CLR(c->fd, &serv->fd_read);
  c->handler = handle_graph;
  send_graph_init_msz(serv, c);
  send_graph_init_mct(serv, c);
  send_graph_init_tna(serv, c);
  return (0);
}

int	cmp_team(t_server *serv, t_client *c, int i)
{
  if (serv->teams[i].clients->nb_client >= serv->teams[i].clients->nb_max)
    {
      printf("team full, check for eggs...\n");
      if (serv->teams[i].nb_free_eggs <= 0)
	{
	  printf("no free eggs. client kicked..\n");
	  free(c->p);
	  c->fd_type = FD_GUEST;
	  c->handler = handle_guest;
	  serv->guest->pop(serv->guest, c);
	  serv->too_much_clients(c, serv->teams[i], serv);
	  return (-1);
	}
      else
	serv->teams[i].nb_free_eggs--;
    }
  else
    {
      serv->teams[i].clients->push(serv->teams[i].clients, c);
      serv->guest->pop(serv->guest, c);
      FD_CLR(c->fd, &serv->fd_read);
      c->handler = handle_client;
    }
  display_team_info(serv, c, i);
  return (0);
}

int	log_client(t_server *serv, t_client *c, int fd, t_cmd *cmd)
{
  int	i;

  (void)fd;
  if ((c->p = malloc(sizeof(t_player))) == NULL)
    return (-1);
  c->p->q = construct_ia_q();
  c->p->turn = rand() % 3;
  c->p->pv = (1260.0 / (double)serv->args->freq);
  c->p->inventory = construct_inventory();
  c->p->lvl = 1;
  c->p->name = strdup("not assigned");
  c->p->positions.x = 0;
  c->p->positions.y = 0;
  if (c->fd_type == FD_CLIENT)
    {
      for (i = 0; i < serv->args->nb_team; i++)
	{
	  if (strncmp(serv->teams[i].name, cmd->cmd,
		      strlen(serv->teams[i].name)) == 0)
	    return (cmp_team(serv, c, i));
	}
    }
  else if (c->fd_type == FD_GRAPH)
    switch_to_graph(serv, c);
  return (0);
}
