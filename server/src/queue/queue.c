/*
** queue.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src/queue
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 18:59:42 2017 beche
** Last update Sun Jul  2 16:16:11 2017 Elodie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"

static int	push(t_ia_q *q, t_cmd *cmd)
{
  if (q->nb_cmd >= 9)
    return (-1);
  int	i;

  i = 0;
  while (q->cmd[i] != NULL)
    {
      i++;
    }
  if (i == 10)
    return (-1);
  q->cmd[i] = cmd;
  q->nb_cmd++;
  printf("pushing md at index N° %d\n", i);
  return (0);
}

static int	queue_is_empty(t_ia_q *q)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (i < 10)
    {
      if (q->cmd[i] != NULL)
	n++;
      i++;
    }
  return (n);
}
static t_cmd	*pop(t_ia_q *q)
{

  int	i;
  int n;
  t_cmd	*tmp;

  if (queue_is_empty(q) == 0)
    return (NULL);
  n = 0;
  i = q->to_pop;
  while (q->cmd[i] == NULL && n < 20)
    {
      n++;
      i = (i + 1) % 10;
      printf("check i => %d\n", i);
    }
  if (q->cmd[i] != NULL)
    {
      q->nb_cmd--;
      printf("pop cmd N° %d from queue\n", i);
      tmp = q->cmd[i];
      q->cmd[i] = NULL;
      q->to_pop = (q->to_pop + 1) % 10;
      return (tmp);
    }
  return (NULL);
}

int	init_cmd(t_ia_q *ia)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      ia->cmd[i] = NULL;
      i++;
    }
  return (0);
}
t_ia_q	*construct_ia_q()
{
  t_ia_q	*q;

  if ((q = malloc(sizeof(t_ia_q))) == NULL)
    return (NULL);
  if ((q->cmd = malloc(sizeof(t_cmd*) * 11)) ==NULL)
    return (NULL);
  init_cmd(q);
  q->to_pop = 0;
  q->nb_cmd = 0;
  q->push = push;
  q->pop = pop;
  return (q);
}
