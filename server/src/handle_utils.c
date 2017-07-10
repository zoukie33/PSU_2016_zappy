/*
** handle_utils.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 19:59:10 2017 beche
** Last update Sun Jul  2 16:12:38 2017 Elodie
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <server.h>
#include <client.h>

int		is_valid_team(t_server *serv, char *str)
{
  int		i;

  i = 0;
  while (i < serv->args->nb_team)
    {
      if (strncmp(serv->args->nameT[i], str,
		  strlen(serv->args->nameT[i])) == 0)
	return (0);
      i++;
    }
  return (-1);
}

void		quit_client(t_server *serv, t_c_list *l, t_client *c)
{
  printf("client disconnected\n");
  if (c)
    {
      FD_CLR(c->fd, &serv->fd_read);
      c->fd_type = FD_FREE;
    }
  if (l)
    l->pop(l, c);
  if (c)
    close(c->fd);
}

char		*m_read(t_server *serv, t_client *c, t_c_list *l)
{
  int		m;
  int		k;
  int		ret;
  char		buf;
  char		*buffer;

  if ((buffer = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  memset(buffer, 0 , 4095);
  m = 0;
  k = 0;
  while (m == 0)
    {
      if ((ret = read(c->fd, &buf, 1)) == 0)
	{
	  quit_client(serv, l, c);
	  return (NULL);
	}
      buffer[k++] = buf;
      if (buf == '\n')
	m = 1;
    }
  buffer[k] = 0;
  return (buffer);
}
