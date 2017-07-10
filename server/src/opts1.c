/*
** opts1.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy/srv/src
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Thu Jun 15 13:58:56 2017 Elodie
** Last update Sun Jul  2 12:16:55 2017 Elodie
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

char		**opts()
{
  char		**opts;

  if ((opts = malloc(sizeof(char *) * 7)) == NULL)
    return (NULL);
  if ((opts[0] = strdup("-p")) == NULL ||
      (opts[1] = strdup("-x")) == NULL ||
      (opts[2] = strdup("-y")) == NULL ||
      (opts[3] = strdup("-n")) == NULL ||
      (opts[4] = strdup("-c")) == NULL ||
      (opts[5] = strdup("-f")) == NULL)
    return (NULL);
  opts[6] = NULL;
  return (opts);
}

int		check_opt(char **opts, char *curr)
{
  int		i;

  i = 0;
  while (opts[i])
    {
      if (strcmp(curr, opts[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		is_opt(char **av, int ac, t_args *arg, int exec)
{
  int		i;
  char		**opt;
  m_int		funct[6];
  char		**save;

  if (ac < 13)
      return (1);
  save = av;
  funct[0] = &p_opt;
  funct[1] = &x_opt;
  funct[2] = &y_opt;
  funct[3] = &n_opt;
  funct[4] = &c_opt;
  funct[5] = &f_opt;
  opt = opts();
  for (i = 0; av[i] != NULL ; i++)
    {
      if ((exec = check_opt(opt, av[i])) != -1)
	{
	  if ((funct[exec](av, arg, i, ac)) == 1)
	    return (1);
	  av = save;
	}
    }
  return (0);
}

int             p_opt(char **av, t_args *arg, int pos, int ac)
{
  int   i;
  (void)ac;

  i = pos;
  i++;
  if (av[i] != NULL && is_num(av[i]) == 0)
    arg->port = atoi(av[i]);
  else{
    printf("Usage: ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
    printf("-n [NAME1] [NAME2] [...] -c [NB_CLIENTS] -f [FREQ]\n");
    return (1);
  }
  return (0);
}

int             x_opt(char **av, t_args *arg, int pos, int ac)
{
  int   i;

  (void)ac;
  i = pos;
  i++;
  if (av[i] != NULL && is_num(av[i]) == 0)
    arg->dim.x = atoi(av[i]);
  else
    {
      printf("Usage: ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      printf("-n [NAME1] [NAME2] [...] -c [NB_CLIENTS] -f [FREQ]\n");
      return (1);
    }
  return (0);
}

