/*
** graph.h for  in /home/beche/PSU_2016_zappy/francois/inc
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 15:07:33 2017 beche
** Last update Sun Jul  2 10:56:12 2017 beche
*/

#include "ia.h"

#ifndef GRAPH_H_
# define GRAPH_H_

#define NB_GRAPH_CMD 26

typedef struct	s_cmd_graph
{
  t_handler	cmd[NB_GRAPH_CMD];

  m_int		is_GRAPH;
  m_int		push_cmd;
}		t_cmd_graph;

t_cmd_graph	*construct_cmd_graph(t_cmd_graph*);
#endif /* !GRAPH_H_ */
