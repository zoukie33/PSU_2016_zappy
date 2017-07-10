/*
** parser_utils.c for  in /home/beche/PSU_2016_zappy/srv/src/cmd_parser
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 15 12:40:43 2017 beche
** Last update Sun Jul  2 16:22:27 2017 Elodie
*/
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <server.h>

int	get_nb_arg(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != 0)
    {
      if (str[i] == ' ')
	n++;
      i++;
    }
  return (n);
}

char	**malloc_char_2d(char **tab, int x, int y)
{
  int	yy;

  yy = 0;
  if ((tab = malloc(sizeof(char*) * (y + 1) )) == NULL)
    return (NULL);
  tab[y] = NULL;
  while (yy < y)
    {
      if ((tab[yy] = malloc(sizeof(char) * x + 1)) == NULL)
	return (NULL);
      memset(tab[yy], 0, x);
      yy++;
    }
  return (tab);
}

char	**fill_tab(char *buf, char **tab)
{
  int	i;
  int	x;
  int	y;

  x = 0;
  y = 0;
  i = 0;
  while (buf[i] != 0)
    {
      if (buf[i] == ' ')
	{
	  y++;
	  x = 0;
	}
      else
	{
	  if (buf[i] != '\n' && buf[i] != '\r')
	    tab[y][x++] = buf[i];
	}
      i++;
    }
  return (tab);
}

void	display_cmd(t_cmd *cmd)
{
  int  i;

  i = 0;
  printf("nb arg = %d - cmd =  |||%s|||\n", cmd->nb_arg, cmd->cmd);
  while (cmd->arg[i] != NULL)
    {
      printf("|||%s|||\n", cmd->arg[i]);
      i++;
    }
}
