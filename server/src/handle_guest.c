/*
** handle_guest.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 19:53:29 2017 beche
** Last update Sun Jul  2 20:09:20 2017 Elodie
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <server.h>

void		handle_guest(t_server *serv, t_client *c)
{
  char		*str;
  t_cmd		*cmd;
  char		*buffer;

  printf("handler guest\n");
  if ((cmd = malloc(sizeof(t_cmd))) == NULL)
    return ;
  if ((buffer = m_read(serv, c, serv->guest)) == NULL)
    return ;
  c->rb->rb_write(c->rb, buffer);
  str = c->rb->rb_read_first_cmd(c->rb);
  if (cmd_parser(str, cmd) == NULL)
    {
      dprintf(2, "ERROR: Fail to parse cmd\n");
      return ;
    }
  if (strncmp(cmd->cmd, "GRAPHIC", strlen("GRAPHIC")) == 0)
    c->upgrade(serv, c, FD_GRAPH, cmd);
  else if (is_valid_team(serv, cmd->cmd) == 0)
    c->upgrade(serv, c, FD_CLIENT, cmd);
  else
    printf("unknow cmd guest\n");
}
