/*
** client_tools.c for  in /home/beche/PSU_2016_zappy/copy/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Tue Jun 27 09:19:33 2017 beche
** Last update Sun Jul  2 16:11:43 2017 Elodie
*/

#include <server.h>

t_pos	pos_to_coord(int L, int pos)
{
  t_pos	coord;
  coord.y = pos / L;
  coord.x = pos % L;
  return (coord);
}
