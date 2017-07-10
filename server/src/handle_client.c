/*
** handle_client.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jun 11 16:22:32 2017 beche
** Last update Sun Jul  2 09:47:16 2017 beche
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <server.h>

int	init_client(t_server *serv)
{
  int	i;

  i = 0;
  if ((serv->teams = malloc(sizeof(t_team) *
			    (serv->args->nb_team + 1))) == NULL)
    return (-1);
  while (i < serv->args->nb_team)
    {
      serv->teams[i].name = strdup(serv->args->nameT[i]);
      serv->teams[i].clients = construct_list_client(serv->args->nbClients);
      serv->teams[i].nb_free_eggs = 1;
      i++;
    }
  return (0);
}

void		handle_client(t_server *serv, t_client *c, t_c_list *l)
{
  char		*str;
  t_cmd		*cmd;
  char		*buffer;

  if ((cmd = malloc(sizeof(t_cmd))) == NULL)
    return ;
  printf("handler client\n");
  if ((buffer = m_read(serv, c, l)) == NULL)
    return ;
  c->rb->rb_write(c->rb, buffer);
  str = c->rb->rb_read_first_cmd(c->rb);
  if (cmd_parser(str, cmd) == NULL)
    {
      printf("ERROR: Fail to parse cmd\n");
      return ;
    }
  if (serv->ia_cmd->is_IA(serv->ia_cmd, cmd->cmd) >= 0)
    {
      c->p->q->push(c->p->q, cmd);
    }
  else
    printf("unknow => %s client\n ", cmd->cmd);
}
