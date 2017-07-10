/*
** check_elevation_1.c for  in /home/elodie/C/reseau/El/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sun Jul  2 13:07:49 2017 Elodie
** Last update Sun Jul  2 13:12:19 2017 Elodie
*/

#include "server.h"

bool		check_elevation_1(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 1 &&
      serv->world[y][x].inv->bag[2] == 0 &&
      serv->world[y][x].inv->bag[3] == 0 &&
      serv->world[y][x].inv->bag[4] == 0 &&
      serv->world[y][x].inv->bag[5] == 0 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}

bool		check_elevation_2(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 1 &&
      serv->world[y][x].inv->bag[2] == 1 &&
      serv->world[y][x].inv->bag[3] == 1 &&
      serv->world[y][x].inv->bag[4] == 0 &&
      serv->world[y][x].inv->bag[5] == 0 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}

bool		check_elevation_3(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 2 &&
      serv->world[y][x].inv->bag[2] == 0 &&
      serv->world[y][x].inv->bag[3] == 2 &&
      serv->world[y][x].inv->bag[4] == 0 &&
      serv->world[y][x].inv->bag[5] == 2 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}

bool		check_elevation_4(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 1 &&
      serv->world[y][x].inv->bag[2] == 1 &&
      serv->world[y][x].inv->bag[3] == 2 &&
      serv->world[y][x].inv->bag[4] == 0 &&
      serv->world[y][x].inv->bag[5] == 1 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}

bool		check_elevation_5(t_server *serv, int x, int y)
{
  if (serv->world[y][x].inv->bag[1] == 1 &&
      serv->world[y][x].inv->bag[2] == 2 &&
      serv->world[y][x].inv->bag[3] == 1 &&
      serv->world[y][x].inv->bag[4] == 3 &&
      serv->world[y][x].inv->bag[5] == 0 &&
      serv->world[y][x].inv->bag[6] == 0)
    return (true);
  return (false);
}
