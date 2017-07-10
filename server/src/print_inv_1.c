/*
** print_inv_1.c for print_inv in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy/src
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 15:46:01 2017 zoukie
** Last update Sun Jul  2 21:36:23 2017 Elodie
*/

#include "server.h"

void	print_food(t_server *serv, int inc, int inventory, int fd)
{
  int   i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " food");
}

void	print_linemate(t_server *serv, int inc, int inventory, int fd)
{
  int   i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " linemate");
}

void	print_deraumere(t_server *serv, int inc, int inventory, int fd)
{
  int   i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " deraumere");
}

void	print_sibur(t_server *serv, int inc, int inventory, int fd)
{
  int	i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " sibur");
}

void	print_mendiane(t_server *serv, int inc, int inventory, int fd)
{
  int	i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " mendiane");
}
