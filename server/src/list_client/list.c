/*
** list.c for  in /home/beche/OMG/PSU_2016_zappy/francois/src/list_client
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 12:11:03 2017 beche
** Last update Sun Jul  2 16:21:19 2017 Elodie
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "list_client.h"

static int	push(t_c_list *l, t_client *c)
{
  if (l->head == NULL && l->tail == NULL)
    {
      printf("first node\n");
      c->prev = NULL;
      c->next = NULL;
      l->head = c;
      l->tail = c;
    }
  else
    {
      printf("new node\n");
      l->tail->next = c;
      c->next = NULL;
      c->prev = l->tail;
      l->tail = c;
    }
  l->nb_client++;
  return (0);
}

static int	pop(t_c_list *l, t_client *c)
{
  t_client     *tmp;

  tmp = l->head;
  while (tmp != NULL)
    {
      if (tmp == c)
	{
	  printf("POPING\n");
	  if (tmp->prev)
	    tmp->prev->next = tmp->next;
	  else
	    l->head = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  else
	    l->tail = tmp->prev;
	  l->nb_client--;
	}
      tmp = tmp->next;
    }
  return (0);
}

t_c_list	*construct_list_client(int max)
{
  t_c_list	*l;

  if ((l = malloc(sizeof(t_c_list))) == NULL)
    return (NULL);
  l->head = NULL;
  l->tail = NULL;
  l->nb_client = 0;
  l->nb_max = max;
  l->push = push;
  l->pop = pop;
  return (l);
}
