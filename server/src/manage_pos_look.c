/*
** manage_pos_look.c for manage_pos in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy/src
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 15:40:10 2017 zoukie
** Last update Sun Jul  2 20:57:18 2017 Elodie
*/

#include "server.h"

int	manage_pos_y(int move_y, t_server *serv)
{
  if (move_y < 0)
    {
      move_y = 0;
      return (move_y);
    }
  else if (move_y > serv->args->dim.y - 1)
    {
      move_y = serv->args->dim.y;
      return (move_y);
    }
  return (move_y);
}

int	manage_pos_x(int move_x, t_server *serv)
{
  if (move_x < 0)
    {
      move_x = 0;
      return (move_x);
    }
  else if (move_x > serv->args->dim.x - 1)
    {
      move_x = serv->args->dim.x;
      return (move_x);
    }
  return (move_x);
}

int	manage_delim(int delim, t_server *serv)
{
  if (delim < 0)
    {
      delim = 0;
      return (delim);
    }
  else if (delim > serv->args->dim.x)
    {
      delim = 9;
      return (delim);
    }
  return (delim);
}
