/*
** list_client.h for  in /home/beche/OMG/PSU_2016_zappy/francois/src/list_client
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Fri Jun 30 12:05:34 2017 beche
** Last update Sun Jul  2 10:58:25 2017 beche
*/

#include "client.h"

#ifndef LIST_CLIENT_H_
# define LIST_CLIENT_H_

typedef	struct	s_c_list*	(*m_list)();

typedef struct			s_c_list
{
  t_client			*head;
  t_client			*tail;
  int				nb_client;
  int				nb_max;
  m_int				push;
  m_int				pop;
}				t_c_list;

t_c_list			*construct_list_client(int);
#endif
