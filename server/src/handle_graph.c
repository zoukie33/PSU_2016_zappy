/*
** handle_graph.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 19:57:05 2017 beche
** Last update Sun Jul  2 09:48:41 2017 beche
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <server.h>

void		handle_graph(t_server *serv, t_client *c)
{
  char		*buffer;
  char		*str;
  t_cmd		cmd;
  int		index;

  (void)serv;
  printf("handler graphique\n");
  if ((buffer = m_read(serv, c, serv->graph)) == NULL)
    return ;
  c->rb->rb_write(c->rb, buffer);
  str = c->rb->rb_read_first_cmd(c->rb);
  if (cmd_parser(str, &cmd) == NULL)
    {
      printf("ERROR: Fail to parse cmd\n");
      return ;
    }
  if ((index = serv->g_cmd->is_GRAPH(serv->g_cmd, cmd.cmd)) >= 0)
    serv->g_cmd->cmd[index].handle_cmd(serv, &cmd, c->fd);
}
