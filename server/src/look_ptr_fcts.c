/*
** look_prt_fcts.c for  in /home/elodie/C/reseau/PSU_2016_zappy/copy
** 
** Made by Elodie
** Login   <elodie>
** 
** Started on  Sun Jun 25 13:38:09 2017 Elodie
** Last update Sun Jul  2 19:30:25 2017 Elodie
*/

#include "server.h"

void        exec_look_fct(t_world **tiles, t_server *serv,
                          int fd)
{
  fct    fct_look[4];
  t_client	*tmp;
  (void)serv;
  (void)fd;
  (void)tiles;

  tmp = find_client(serv, fd);
  fct_look[0] = look_North;
  fct_look[1] = look_East;
  fct_look[2] = look_South;
  fct_look[3] = look_West;
  fct_look[tmp->p->turn](serv, fd);
}
