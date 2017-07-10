/*
** cmd_graph.c for  in /home/beche/PSU_2016_zappy/francois/src/cmd
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 15:17:31 2017 beche
** Last update Sun Jul  2 16:14:47 2017 Elodie
*/

#include <string.h>
#include <stdlib.h>
#include <server.h>
#include "graph.h"

static int		is_GRAPH(t_cmd_graph *g, char *cmd)
{
  int			i;

  for (i = 0; i < NB_GRAPH_CMD; i++)
    {
      printf("name = %s\n", g->cmd[i].name);
      if (g->cmd[i].used == 1 && strncmp(g->cmd[i].name,
					 cmd, strlen(cmd)) == 0)
	return (i);
    }
  return (-1);
}

static int		push_cmd(t_handler *h, char *name, m_void fct)
{
  h->used = 1;
  h->handle_cmd = fct;
  h->name = strdup(name);
  h->time = 0;
  return (0);
}

void		assign_ptr_graph(t_cmd_graph *g)
{
  g->push_cmd(&g->cmd[0], "msz", cmd_msz);
  g->push_cmd(&g->cmd[1], "bct", cmd_bct);
  g->push_cmd(&g->cmd[2], "mct", cmd_mct);
  g->push_cmd(&g->cmd[3], "tna", cmd_tna);
  g->push_cmd(&g->cmd[4], "pnw", cmd_pnw);
  g->push_cmd(&g->cmd[5], "ppo", cmd_ppo);
}

t_cmd_graph	*construct_cmd_graph(t_cmd_graph *g)
{
  if ((g = malloc(sizeof(t_cmd_graph))) == NULL)
    return (NULL);
  g->is_GRAPH = is_GRAPH;
  g->push_cmd = push_cmd;
  assign_ptr_graph(g);
  return (g);
}
