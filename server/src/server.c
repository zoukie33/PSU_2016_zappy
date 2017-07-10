/*
** server.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jun 11 15:26:46 2017 beche
** Last update Sun Jul  2 16:12:52 2017 Elodie
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <server.h>

static double		get_ms_time()
{
  struct timeval	tv;
  double		time_in_mill;

  gettimeofday(&tv, NULL);
  time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
  return (time_in_mill);
}

static void		too_much_clients(t_client *client, t_team *l, t_server *c)
{
  (void)l;
  (void)c;
  write(client->fd, "Too Much User connected\n",
	strlen("Too Much User connected\n"));
  printf("Client %d ejected :  too much client connected\n", client->fd);
  FD_CLR(client->fd, &c->fd_read);
  close(client->fd);
}

static int		accept_client(t_server *c)
{
  int			fd_client;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((fd_client = accept(c->fd, (struct sockaddr *)&client_sin,
			  &client_sin_len)) == -1)
    return (-1);
  printf("connection entrante\n");
  dprintf(fd_client, "WELCOME\n");
  c->guest->push(c->guest, construct_client(fd_client, c));
  return (0);
}

static int		run_server(t_server *serv)
{
  struct timeval	tv;
  int			fd_max;
  int			sel;

  printf("Starting server...\n");
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  while (42)
    {
      my_fd_set(serv, &fd_max);
      if ((sel = select(fd_max + 1, &serv->fd_read, NULL, NULL, &tv) == -1))
        {
          perror("select");
          return (-1);
        }
      my_fd_isset(serv);
    }
  return (0);
}

t_server	*construct_server(t_server *c, t_args *arg)
{
  if ((c = malloc(sizeof(t_server))) == NULL)
    return (NULL);
  c->args = arg;
  c->sin.sin_family = AF_INET;
  c->sin.sin_port = htons(c->args->port);
  c->sin.sin_addr.s_addr = INADDR_ANY;
  c->fd = 0;
  if (my_socket(c, 1) == 1)
    {
      write(2, "ERROR on my_socket : Function crashed\n", 38);
      return (NULL);
    }
  FD_ZERO(&c->fd_read);
  c->ia_cmd = construct_cmd_ia(c->ia_cmd, c);
  c->g_cmd = construct_cmd_graph(c->g_cmd);
  c->run_server = run_server;
  c->accept = accept_client;
  c->too_much_clients = too_much_clients;
  c->guest = construct_list_client(255);
  c->graph = construct_list_client(255);
  c->get_ms_time = get_ms_time;
  if (init_client(c) == -1)
    printf("can't init client\n");
  return (c);
}
