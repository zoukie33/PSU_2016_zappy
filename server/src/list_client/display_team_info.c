/*
** display_team_info.c for  in /home/beche/OMG/PSU_2016_zappy/El/src/list_client
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jul  2 11:21:18 2017 beche
** Last update Sun Jul  2 11:23:23 2017 beche
*/

#include <stdio.h>
#include <server.h>
#include <client.h>

void	display_team_info(t_server *serv, t_client *c, int i)
{
  dprintf(c->fd, "%d\n%d %d\n",
	  serv->teams[i].clients->nb_max - serv->teams[i].clients->nb_client,
	  c->p->positions.x, c->p->positions.y);
}
