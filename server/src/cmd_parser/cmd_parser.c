/*
** cmd_parser.c for  in /home/beche/PSU_2016_zappy/srv/src/cmd_parser
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Thu Jun 15 12:24:16 2017 beche
** Last update Sun Jul  2 10:11:13 2017 beche
*/

#include <string.h>
#include <server.h>

char	*get_cmd_name(char *str, t_cmd *cmd)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != ' ' && str[i] != 0)
    {
      if (str[i] != '\r' && str[i] != '\n')
	cmd->cmd[j++] = str[i];
      i++;
    }
  cmd->cmd[j] = 0;
  return (&str[i + 1]);
}

t_cmd	*cmd_parser(char *buf, t_cmd *cmd)
{
  char	*head;
  int	nb_arg;

  (void)head;
  if (buf[0] == '\r' && buf[1] == '\n')
    return (NULL);
  cmd->arg = NULL;
  head = get_cmd_name(buf, cmd);
  nb_arg = get_nb_arg(head);

  if ((cmd->arg = malloc_char_2d(cmd->arg, strlen(buf), nb_arg)) == NULL)
    return (NULL);
  cmd->arg = fill_tab(head, cmd->arg);
  if (cmd->arg[0][0] == 0)
    cmd->nb_arg = 0;
  else
    cmd->nb_arg = nb_arg;
  cmd->time = 0;
  display_cmd(cmd);
  return (cmd);
}
