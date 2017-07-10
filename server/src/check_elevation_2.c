/*
** check_elevation_1.c for  in /home/elodie/C/reseau/El/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sun Jul  2 13:07:49 2017 Elodie
** Last update Sun Jul  2 13:13:27 2017 Elodie
*/

#include "server.h"

bool		check_elevation_6(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 1 &&
      serv->world[y][x].inv->bag[2] == 2 &&
      serv->world[y][x].inv->bag[3] == 3 &&
      serv->world[y][x].inv->bag[4] == 0 &&
      serv->world[y][x].inv->bag[5] == 1 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}

bool		check_elevation_7(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 2 &&
      serv->world[y][x].inv->bag[2] == 2 &&
      serv->world[y][x].inv->bag[3] == 2 &&
      serv->world[y][x].inv->bag[4] == 2 &&
      serv->world[y][x].inv->bag[5] == 2 &&
      serv->world[y][x].inv->bag[6] == 1)
    return (true);
  return (false);
}
