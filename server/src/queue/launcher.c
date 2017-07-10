/*
** time.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src/queue
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 20:48:17 2017 beche
** Last update Sun Jul  2 10:19:37 2017 beche
*/

#include <stdlib.h>
#include <time.h>
#include <server.h>
#include <queue.h>
#include <launcher.h>

int		check_life(t_server *s, t_client *c, t_c_list *l)
{
  double	timestamp;

  timestamp = s->get_ms_time();
  if (timestamp > c->timestamp)
    {
      if (c->timestamp > 0)
	c->p->pv -= ((timestamp - c->timestamp) / 1000);
      c->timestamp = s->get_ms_time();
      if (c->p->pv <= 0.0)
      	{
      	  dprintf(c->fd, "pdi %d\r\n", c->id);
	  quit_client(s, l, c);
      	}
    }
  return (0);
}

int		launcher(t_server *s, t_client *c)
{
  t_cmd		*cmd;
  int		index;

  cmd = NULL;
  if (s->get_ms_time() >= c->launcher->next_pop)
    {
      cmd = c->p->q->pop(c->p->q);
      if (cmd == NULL)
	return (-1);

      printf("CMD LAUNCHER => %s\n", cmd->cmd);
      if ((index = s->ia_cmd->is_IA(s->ia_cmd, cmd->cmd)) >= 0)
	{
	  printf("launch %s\n", cmd->cmd);
	  c->launcher->next_pop = (s->get_ms_time() + s->ia_cmd->cmd[index].time);
	  printf("atm + cmd->time = next_pop\n");
	  printf("%f + %f = %f\n", s->get_ms_time(),
		 s->ia_cmd->cmd[index].time , c->launcher->next_pop);
	  s->ia_cmd->cmd[index].handle_cmd(s, cmd, c->fd);
	  free(cmd);
	}
    }
  return (0);
}

static int	set_next_pop(t_launcher *l, t_cmd *cmd)
{
  (void)l;
  (void)cmd;
  return (0);
}

t_launcher	*construct_launcher()
{
  t_launcher	*l;

  if ((l = malloc(sizeof(t_launcher))) == NULL)
    return (NULL);
  l->next_pop = 0;
  l->set_next_pop = set_next_pop;
  return (l);
}

