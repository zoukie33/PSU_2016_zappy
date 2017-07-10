/*
** ia.h for  in /home/beche/PSU_2016_zappy/francois/src/cmd
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 15:56:59 2017 beche
** Last update Sun Jul  2 11:08:57 2017 beche
*/

#ifndef IA_H_
# define IA_H_

#define NB_IA_CMD 13

typedef int(*m_int)();
typedef void(*fct)();

typedef struct          s_handler
{
  int			used;
  char			*name;
  fct			handle_cmd;
  double		time;
}			t_handler;

typedef struct		s_cmd_ia
{
  t_handler		cmd[NB_IA_CMD];
  m_int			is_IA;
  m_int			push_cmd;
}			t_cmd_ia;

#endif /* !IA_H_ */
