/*
** cmd_ia.c for  in /home/beche/PSU_2016_zappy/francois/src/cmd
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 15:06:54 2017 beche
** Last update Sun Jul  2 23:05:24 2017 Elodie
*/

#include <string.h>
#include <stdlib.h>
#include <server.h>
#include <ia.h>

static int		is_IA(t_cmd_ia *ia, char *cmd)
{
  int	i;

  for (i = 0; i < NB_IA_CMD; i++)
    {
      if ( ia->cmd[i].used == 1 &&
	   strncmp(ia->cmd[i].name, cmd, strlen(cmd)) == 0)
	return (i);
    }
  return (-1);
}

static int		push_cmd(t_handler *h, char *name, fct fct, double time)
{
  h->used = 1;
  h->handle_cmd = fct;
  h->name = strdup(name);
  h->time = time;
  printf("---------------------------%s take %f times\n", name, time);
  return (0);
}

void		init_tab(t_cmd_ia *ia)
{
  int	i;

  i = 0;
  while (i < NB_GRAPH_CMD)
    {
      ia->cmd[i].used = 0;
      i++;
    }
}

void		assign_ptr_ia(t_cmd_ia *ia, t_server *s, double t)
{
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[1], "Broadcast", cmd_broadcast, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[0], "Eject", cmd_eject, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[2], "Forward", cmd_forward, t);
  t = (1 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[3], "Inventory", cmd_inventory, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[4], "Look", cmd_look, 7);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[5], "Set", cmd_set, t);
  t = (0 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[6], "Connect_nbr", cmd_connect_nbr, t);
  t = (42 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[7], "Fork", cmd_fork, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[8], "Left", cmd_left, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[9], "Right", cmd_right, t);
  t = (7 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[10], "Take", cmd_take, t);
  t = (300 * 1000) / s->args->freq;
  ia->push_cmd(&ia->cmd[11], "Incantation", cmd_incantation, t);
}

t_cmd_ia	*construct_cmd_ia(t_cmd_ia *ia, t_server *s)
{
  double	t;

  t = 0;
  printf("CONSTRUCTION DE CMD_IA\n");
  if ((ia = malloc(sizeof(t_cmd_ia))) == NULL)
    return (NULL);
  init_tab(ia);
  ia->is_IA = is_IA;
  ia->push_cmd = push_cmd;
  assign_ptr_ia(ia, s, t);
  return (ia);
}
