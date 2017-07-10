/*
** server_tools.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jun 11 16:08:03 2017 beche
** Last update Sun Jul  2 10:02:34 2017 beche
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <server.h>

void		my_fd_set_2(t_server *serv, int *fd_max, t_client *tmp)
{
  for (tmp = serv->guest->head; tmp != NULL; tmp = tmp->next)
    {
      if (tmp->fd_type != FD_FREE)
	{
	  FD_SET(tmp->fd, &serv->fd_read);
	  if (*fd_max < tmp->fd)
	    *fd_max = tmp->fd;
	}
    }
  for (tmp = serv->graph->head; tmp != NULL; tmp = tmp->next)
    {
      FD_SET(tmp->fd, &serv->fd_read);
      if (*fd_max < tmp->fd)
	*fd_max = tmp->fd;
    }
}

void		my_fd_set(t_server *serv, int *fd_max)
{
  t_client	*tmp;
  int		i;

  i = 0;
  tmp = NULL;
  FD_ZERO(&serv->fd_read);
  FD_SET(serv->fd, &serv->fd_read);
  *fd_max = 4;
  my_fd_set_2(serv, fd_max, tmp);
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head; tmp != NULL; tmp = tmp->next)
  	{
  	  FD_SET(tmp->fd, &serv->fd_read);
  	  if (*fd_max < tmp->fd)
  	    *fd_max = tmp->fd;
	  check_life(serv, tmp, serv->teams[i].clients);
	  launcher(serv, tmp);
  	}
      i++;
    }
}

void		my_fd_isset(t_server *serv)
{
  int		i;
  t_client	*tmp;

  i = 0;
  if (FD_ISSET(serv->fd, &serv->fd_read))
    serv->accept(serv);
  for (tmp = serv->guest->head; tmp != NULL; tmp = tmp->next)
    {
      if (FD_ISSET(tmp->fd, &serv->fd_read))
	tmp->handler(serv, tmp);
    }
  for (tmp = serv->graph->head; tmp != NULL; tmp = tmp->next)
    {
      if (FD_ISSET(tmp->fd, &serv->fd_read))
	tmp->handler(serv, tmp);
    }
  while (i < serv->args->nb_team)
    {
      for (tmp = serv->teams[i].clients->head; tmp != NULL; tmp = tmp->next)
  	{
  	  if (FD_ISSET(tmp->fd, &serv->fd_read))
	    tmp->handler(serv, tmp, serv->teams[i].clients);
  	}
      i++;
    }
}

int		my_socket(t_server *serv, int opt)
{
  if ((serv->fd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "ERROR on my_socket : can't create socket\n",
	    strlen("ERROR on my_socket : can't create socket\n"));
      return (1);
    }
  if (setsockopt(serv->fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    return (1);
  if (bind(serv->fd, (struct sockaddr*)&serv->sin, sizeof(serv->sin)) == -1)
    {
      close(serv->fd);
      write(2, "ERROR on my_socket : can't bind socket\n",
	    strlen("ERROR on my_socket : can't bind socket\n"));
      return (1);
    }
  if (listen(serv->fd, 42) == -1)
    {
      write(2, "ERROR on my_socket : can't listen socket\n",
	    strlen("ERROR on my_socket : can't listen socket\n"));
      return (1);
    }
  return (0);
}
