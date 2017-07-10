//
// main.cpp for  in /home/elodie/C/reseau/Zappy/client/srcs
// 
// Made by Elodie
// Login   <elodie>
// 
// Started on  Wed Jun  7 17:03:08 2017 Elodie
// Last update Sun Jul  2 18:27:15 2017 
//

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <string.h>
# include <iostream>

# include "Game.hh"
# include "All.hh"

std::list< std::string > Teams;
std::list< std::list<int> > Players;
std::list< std::list<int> > PlayersLevels;
std::list< std::list<int> > PlayersInventorys;
std::vector<Player*>       PlayersList;

int   StartWindows(int port, std::string ip)
{
    sf::Music		music;
  
  if (!music.openFromFile("media/Niska.ogg"))
    return -1;
  music.setLoop(true);
  music.play();
  Game *game = new Game(port, ip);
  game->getGraphical()->getMap();
  game->boucle();
  return 0;
}

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
  std::string machine;
  int         port = 0;
  int         i = 0;

  if (ac < 3){
    std::cout << "USAGE : ./zappy_ai -p port -h [machine]" << std::endl;
    std::cout << "        port    is the port number" << std::endl;
    std::cout << "        machine is a name of the machine; localhost by default" << std::endl;
    return -1;
  }
  else
    {
      while (av[i]){
        if ((strcmp(av[i], "-p")) == 0 && av[i+1]){
          if ((isaNumber(av[i+1])) == 1)
            port = atoi(av[i+1]);
        }
        else if ((strcmp(av[i], "-h")) == 0 && av[i+1])
          machine.assign(av[i+1], strlen(av[i+1]));
        i++;
      }
      std::cout << "Port = " << port << std::endl;
      std::cout << "Ip = " << machine << std::endl;
      // SFML
      StartWindows(port, machine);
    }
  return 0;
}
