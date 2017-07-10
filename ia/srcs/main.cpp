//
// main.cpp for  in /home/elodie/C/reseau/Zappy/client/srcs
//
// Made by Elodie
// Login   <elodie>
//
// Started on  Wed Jun  7 17:03:08 2017 Elodie
// Last update Sun Jul  2 15:13:26 2017 Bourreau Quentin
//

# include <string.h>
# include <iostream>

# include "Game.hh"

int   isaNumber(char *str)
{
  int i;
  int length = strlen(str);

  for (i=0;i<length;i++){
    if (!isdigit(str[i]))
      return (0);
  }
  return (1);
}

int		main(int ac, char **av)
{
  std::string	team;
  std::string	machine;
  int		port = 0;
  int		i = 0;

  if (ac < 5){
    std::cout << "USAGE : ./zappy_ai -p port -n name -h [machine]" << std::endl;
    std::cout << "        port    is the port number" << std::endl;
    std::cout << "        name    is a name of the team" << std::endl;
    std::cout << "        machine is a name of the machine; localhost by default" << std::endl;
    return -1;
  }
  while (av[i]){
    if ((strcmp(av[i], "-p")) == 0 && av[i+1]){
      if ((isaNumber(av[i+1])) == 1)
	port = atoi(av[i+1]);
    }
    else if ((strcmp(av[i], "-n")) == 0 && av[i+1])
      team.assign(av[i+1], strlen(av[i+1]));
    else if ((strcmp(av[i], "-h")) == 0 && av[i+1])
      machine.assign(av[i+1], strlen(av[i+1]));
    i++;
  }
  Game		game(port, team, machine);
  std::cout << "Port = " << game.getPort() << std::endl;
  std::cout << "Team = " << game.getTeam() << std::endl;
  std::cout << "Ip = " << game.getIp() << std::endl;
  return 0;
}
