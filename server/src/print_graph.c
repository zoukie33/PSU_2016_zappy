/*
** print_graph.c for  in /home/elodie/C/reseau/PSU_2016_zappy/El/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sat Jul  1 18:13:53 2017 Elodie
** Last update Sat Jul  1 18:17:57 2017 Elodie
*/

#include "server.h"

void		print_graph(t_server *serv, const char *print)
{
  t_client	*tmp;

  for (tmp = serv->graph->head ; tmp != NULL ; tmp = tmp->next)
    {
      dprintf(tmp->fd, "%s\n", print);
    }
}
