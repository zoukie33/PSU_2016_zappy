/*
** client.h for  in /home/beche/PSU_2016_zappy/francois/inc
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 29 16:30:31 2017 beche
** Last update Sun Jul  2 23:02:43 2017 Elodie
*/

#ifndef CLIENT_H_
#define CLIENT_H_
#include "mtype.h"
#include "rb.h"
#include "queue.h"
#include "launcher.h"

typedef struct			s_inv
{
  int				bag[MAX_RESSOURCES];
  m_int				push;
  m_int				pop;
  m_int				reset;
}				t_inv;

t_inv				*construct_inventory();

#define NAME_SIZE 50

typedef struct			s_player
{
  t_ia_q			*q;
  orientation			turn;
  double			pv;
  t_inv				*inventory;
  t_pos				positions;
  int				lvl;
  char				*name;
}				t_player;

typedef struct			s_client
{
  int				id;
  int				fd;
  int				fd_type;
  m_void			handler;
  char				*ip;
  double			timestamp;
  t_rb				*rb;
  t_player			*p;
  struct s_client		*next;
  struct s_client		*prev;
  t_launcher			*launcher;
  m_int				reset;
  m_int				upgrade;
}				t_client;
#endif
