/*
** print_inv_2.c for print_inv_2 in /home/zoukie/epitech/PSU_2016_zappy/Maxence/copy
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun Jul  2 15:51:56 2017 zoukie
** Last update Sun Jul  2 21:38:59 2017 Elodie
*/

#include "server.h"

void	print_phiras(t_server *serv, int inc, int inventory, int fd)
{
  int	i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " phiras");
}

void	print_thystame(t_server *serv, int inc, int inventory, int fd)
{
  int	i;

  for (i = 0; i < serv->world[inc]->inv->bag[inventory]; i++)
    dprintf(fd, " thystame");
}

void	print_bag(t_server *serv, int fd, int inc)
{
  int	inventory;
  static int i = 0;

  inventory = 0;
  while (inventory < 7)
    {
      if (inventory == 0)
	print_food(serv, inc, inventory, fd);
      else if (inventory == 1)
	print_linemate(serv, inc, inventory, fd);
      else if (inventory == 2)
	print_deraumere(serv, inc, inventory, fd);
      else if (inventory == 3)
	print_sibur(serv, inc, inventory, fd);
      else if (inventory == 4)
	print_mendiane(serv, inc, inventory, fd);
      else if (inventory == 5)
	print_phiras(serv, inc, inventory, fd);
      else if (inventory == 6)
	print_thystame(serv, inc, inventory, fd);
      inventory++;
    }
  if (i < (get_nbr_tiles(serv, fd) - 1))
    dprintf(fd, ",");
  i++;
}
