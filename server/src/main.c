/*
** main.c for  in /home/beche/PSU_2016_zappy/srv/src
** 
** Made by beche
** Login   <francois.beche@epitech.eu>
** 
** Started on  Sun Jun 11 13:59:27 2017 beche
** Last update Sun Jul  2 16:45:35 2017 Elodie
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <server.h>

int	start(t_server *serv, int ac, t_args arg)
{
  (void)ac;
  if (arg.nbClients == 0)
  {
    printf("You must have at least one client.\n");
    return (1);
  }
  srand(time(NULL));
    serv = construct_server(serv, &arg);
    printf("1\n");
    init_world(serv);
    serv->run_server(serv);
    return (0);
}

static void display_help()
{
    printf("USAGE: ./zappy_server -p port -x width -y height ");
    printf("-n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\t is the port number\n");
    printf("\twidth\t is the width of the world\n");
    printf("\theight\t is the height of the world\n");
    printf("\tnameX\t is the name of the team X\n");
    printf("\tclientNb is the number of authorized clients per team\n");
    printf("\tfreq\t is the reciprocal of time unit");
    printf(" for execution of actions\n");
}

int	main(int ac, char **av)
{
  t_server	*serv;
  t_args	arg;

    if (ac == 2 && strcmp(av[1], "-help") == 0)
    {
        display_help();
        return (0);
    }
  serv = NULL;
  arg.nb_team = 0;
  arg.freq = 100;
  if (is_opt(av, ac, &arg, 0) == 1)
    return (1);
  start(serv, ac, arg);
  return (0);
}
