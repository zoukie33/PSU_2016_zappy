/*
** queue.h for  in /home/beche/OMG/PSU_2016_zappy/francois/inc
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 18:56:33 2017 beche
** Last update Sun Jul  2 11:00:31 2017 beche
*/

#include "mtype.h"

#ifndef QUEUE_H_
#define QUEUE_H_

typedef t_cmd	*(*m_t_cmd)();
typedef struct	s_ia_q
{
  t_cmd		**cmd;
  int		nb_cmd;
  int		to_pop;
  m_int		push;
  m_t_cmd	pop;
}		t_ia_q;

t_ia_q		*construct_ia_q();
#endif /* !QUEUE_H_ */
