/*
** inventory.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Tue Jun 13 10:43:48 2017 beche
** Last update Sun Jul  2 10:04:11 2017 beche
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <server.h>

static int	push_inventory(t_inv *inv, int type, int quantity)
{
  if (!(type >= 0 && type <= 6) && quantity < 0)
    return (-1);
  inv->bag[type] += quantity;
  return (0);
}

static int	pop_inventory(t_inv *inv, int type, int quantity)
{
  if (!(type >= 0 && type <= 6) && quantity < 0)
    return (-1);
  inv->bag[type] = inv->bag[type] -  quantity;
  if (inv->bag[type] < 0)
    inv->bag[type] = 0;
  return (0);
}

static int	reset(t_inv *inv)
{
  memset(inv->bag, 0, MAX_RESSOURCES);
  return (0);
}

void		print_inventory(t_inv *inv, int fd)
{
  int           i;

  for (i = 0 ; i < MAX_RESSOURCES ; i++)
  {
    dprintf(fd, "%d", inv->bag[i]);
      if (i + 1 != MAX_RESSOURCES)
          dprintf(fd, " ");
  }
  dprintf(fd, "\n");
}

t_inv		*construct_inventory()
{
  t_inv		*inv;
  if ((inv = malloc(sizeof(t_inv))) == NULL)
    return (NULL);
  inv->push = push_inventory;
  inv->pop = pop_inventory;
  inv->reset = reset;
  return (inv);
}
