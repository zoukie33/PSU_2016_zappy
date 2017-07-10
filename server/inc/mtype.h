/*
** mtype.h for  in /home/beche/PSU_2016_zappy/francois/inc
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 17:04:38 2017 beche
** Last update Sun Jul  2 23:03:04 2017 Elodie
*/

#ifndef MTYPE_H_
#define MTYPE_H_

#define FD_FREE 0
#define FD_CLIENT 1
#define FD_SERVER 2
#define FD_GRAPH 3
#define FD_GUEST 4
#define MAX_RESSOURCES 7

#define true 1
#define false 0

typedef int	bool;

typedef int		(*m_int)();
typedef void		(*m_void)();
typedef double		(*m_double)();

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef enum		stones
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }			stones;

typedef enum		orientation
  {
    N = 0,
    E = 1,
    S = 2,
    W = 3
  }			orientation;

typedef struct		s_cmd
{
  int			used;
  int			nb_arg;
  char			cmd[50];
  char			**arg;
  double		time;
}			t_cmd;

#endif
