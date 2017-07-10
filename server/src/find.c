/*
** find.c for  in /home/elodie/C/reseau/El/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sun Jul  2 13:59:43 2017 Elodie
** Last update Sun Jul  2 13:59:59 2017 Elodie
*/

#include "server.h"

t_client        *find_client(t_server *serv, int fd)
{
  int           i;
  t_client      *tmp;

  i = 0;
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head ; tmp != NULL; tmp = tmp->next)
	{
	  if (tmp->fd == fd)
	    return (tmp);
	}
      i++;
    }
  return (NULL);
}
