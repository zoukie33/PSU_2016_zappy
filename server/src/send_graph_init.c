/*
** send_graph_init.c for  in /home/elodie/C/reseau/PSU_2016_zappy/El/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sun Jul  2 19:53:31 2017 Elodie
** Last update Sun Jul  2 20:00:06 2017 Elodie
*/

#include "server.h"

void	send_graph_init_msz(t_server *serv, t_client *c)
{
  t_cmd	*cmd;

  cmd = NULL;
  cmd_msz(serv, cmd, c->fd);
}

void	send_graph_init_mct(t_server *serv, t_client *c)
{
  t_cmd	*cmd;

  cmd = NULL;
  cmd_mct(serv, cmd, c->fd);
}

void	send_graph_init_tna(t_server *serv, t_client *c)
{
  t_cmd	*cmd;

  cmd = NULL;
  cmd_tna(serv, cmd, c->fd);
}
