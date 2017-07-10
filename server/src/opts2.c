/*
** fcts.c for  in /home/elodie/test/getopt
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Wed Jun 14 17:14:32 2017 Elodie
** Last update Sun Jul  2 12:17:57 2017 Elodie
*/
#include <stdlib.h>
#include <string.h>
#include "server.h"

int	is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	str[i] = str[i];
      else
	return (1);
      i++;
    }
  return (0);
}

int		y_opt(char **av, t_args *arg, int pos, int ac)
{
  int	i;

  (void)ac;
  i = pos;
  i++;
  if (av[i] != NULL && is_num(av[i]) == 0)
    arg->dim.y = atoi(av[i]);
  else
    {
      printf("Usage: ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      printf("-n [NAME1] [NAME2] [...] -c [NB_CLIENTS] -f [FREQ]\n");
      return (1);
    }
  return (0);
}

int		n_opt(char **av, t_args *arg, int pos, int ac)
{
  int		i;
  int		x;
  char		**opt;
  char		**teams;

  i = pos;
  x = 0;
  i++;
  opt = opts();
  if ((teams = malloc(sizeof(char *) * 4096)) == NULL)
    return (1);
  while (i != ac && check_opt(opt, av[i]) == -1)
    {
      teams[x] = strdup(av[i]);
      teams[x + 1] = NULL;
      arg->nb_team++;
      x++;
      i++;
    }
  arg->nameT = teams;
  return (0);
}

int 		c_opt(char **av, t_args *arg, int pos, int ac)
{
  int	i;

  (void)ac;
  i = pos;
  i++;
  if (av[i] != NULL && is_num(av[i]) == 0)
    arg->nbClients = atoi(av[i]);
  else
    {
      printf("Usage: ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      printf("-n [NAME1] [NAME2] [...] -c [NB_CLIENTS] -f [FREQ]\n");
      return (1);
    }
  return (0);
}

int 		f_opt(char **av, t_args *arg, int pos, int ac)
{
  int	i;

  (void)ac;
  i = pos;
  i++;
  if (av[i] != NULL && is_num(av[i]) == 0)
    arg->freq = atoi(av[i]);
  else
    {
      printf("Usage: ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      printf("-n [NAME1] [NAME2] [...] -c [NB_CLIENTS] -f [FREQ]\n");
      return (1);
    }
  return (0);
}
