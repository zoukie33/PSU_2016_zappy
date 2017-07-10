//
// Parse.cpp for Parse cpp in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Thu Jun 29 09:43:35 2017 
// Last update Sun Jul  2 19:25:20 2017 
//

# include "ParseSend.hh"

ParseSend::ParseSend(int socketFd)
{
  this->_sockfd = socketFd;
  this->_mapX = 0;
  this->_mapY = 0;
  this->_map = NULL;
  this->_lib = NULL;
}

ParseSend::~ParseSend()
{

}

// Parse cmds

void		ParseSend::parseSizeMap(std::string str)
{
  std::istringstream	isstream;
  std::string		s1;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  this->_mapY = std::stoi(s1);
  std::getline(isstream, s1, ' ');
  this->_mapX = std::stoi(s1);
  Map *map = new Map(this->_mapX, this->_mapY);
  this->_lib->setMap(map);
  this->setMap(map);
}

void		ParseSend::parseTna(std::string str)
{
  std::istringstream	isstream;
  std::string		teamName;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, teamName, ' ');
  std::cout << teamName << std::endl;
  Teams.push_back(teamName);
}

void		ParseSend::parseBct(std::string str)
{
  int			caseX;
  int			caseY;
  std::istringstream	isstream;
  std::string		s1;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  caseX = std::stoi(s1);
  std::getline(isstream, s1, ' ');
  caseY = std::stoi(s1);  
  Case *cas = _map->getCase(caseX, caseY);
  std::getline(isstream, s1, ' ');
  cas->setFood(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setLinemate(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setDeraumere(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setSibur(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setMendiane(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setPhiras(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  cas->setThystame(std::stoi(s1));
}

void		ParseSend::parsePpo(std::string str)
{
  int			idJoueur;
  std::istringstream	isstream;
  std::list<int>	player;
  std::string		s1;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  idJoueur = std::stoi(s1);
  player.push_back(idJoueur);
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  for (std::list<std::list<int>>::iterator it = Players.begin(); it != Players.end(); ++it)
    {
      std::list<int>::iterator it2 = it->begin();
      if (*it2 == idJoueur)
	{
	  std::list<int>::iterator it3 = it->end();

	  player.push_back(*it3);
	  (*it) = player;
    this->_lib->MovePlayer(idJoueur);
  	}
    }
}

void		ParseSend::parsePlv(std::string str)
{
  int			idJoueur;
  std::istringstream	isstream;
  std::list<int>	playerlvl;
  std::string		s1;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  idJoueur = std::stoi(s1);
  playerlvl.push_back(idJoueur);
  std::getline(isstream, s1, ' ');
  playerlvl.push_back(std::stoi(s1));
  for (std::list<std::list<int>>::iterator it = PlayersLevels.begin(); it != PlayersLevels.end(); ++it)
    {
      std::list<int>::iterator it2 = it->begin();
      if (*it2 == idJoueur)
	(*it) = playerlvl;
    }
}

void		ParseSend::parsePnw(std::string str)
{
  std::istringstream	isstream;
  std::list<int>	player;
  std::list<int>	playerlvl;
  std::list<int>	playerInv;
  std::string		s1;
  int			j;

  j = 0;
  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  playerlvl.push_back(std::stoi(s1));
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  player.push_back(std::stoi(s1));
  playerlvl.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  for (std::list<std::string>::iterator it = Teams.begin(); it != Teams.end(); ++it)
    {
      if (*it == s1)
	    player.push_back(j);
      j++;
    }
  Players.push_back(player);
  PlayersLevels.push_back(playerlvl);
  playerInv.push_back(10);
  for (int i = 0; i != 5; ++i)
    playerInv.push_back(0);
  PlayersInventorys.push_back(playerInv);
  this->_lib->AddNewPlayer();
}

void		ParseSend::parsePin(std::string str)
{
  int			idJoueur;
  std::istringstream	isstream;
  std::list<int>	playerInv;
  std::string		s1;

  str = str.substr(4);
  isstream.str(str);
  std::getline(isstream, s1, ' ');
  idJoueur = std::stoi(s1);
  playerInv.push_back(idJoueur);
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  std::getline(isstream, s1, ' ');
  playerInv.push_back(std::stoi(s1));
  for (std::list<std::list<int>>::iterator it = PlayersInventorys.begin(); it != PlayersInventorys.end(); ++it)
    {
      std::list<int>::iterator it2 = it->begin();
      if (*it2 == idJoueur){
	      (*it) = playerInv;
        this->_lib->ChangePlayerInventory(idJoueur);
      }
    }
}

void		ParseSend::parseSeg(std::string str)
{
  (void)str; // todo la func - Victoire d'une équipe -
}


// Send cmds

void		ParseSend::sendMsz()
{
  std::cout << "oui msz vasy" << std::endl;
  if (send(this->_sockfd, "msz\r\n", 5, 0) < 0)
    std::cout << "ERROR: sending msz to server failed." << std::endl;
}

void		ParseSend::sendMct()
{
  if (send(this->_sockfd, "mct\r\n", 5, 0) < 0)
    std::cout << "ERROR: sending mct to server failed." << std::endl;
}

void		ParseSend::sendSqt()
{
  if (send(this->_sockfd, "sqt\r\n", 5, 0) < 0)
    std::cout << "ERROR: sending cmd sqt to server failed." << std::endl;
}

void		ParseSend::sendTna()
{
  if (send(this->_sockfd, "tna\r\n", 5, 0) < 0)
    std::cout << "ERROR: sending cmd tna to server failed." << std::endl;
}

int		ParseSend::checkReaded(std::string str)
{
  if (str == "WELCOME" || str == "BIENVENUE")
    {
      if (send(this->_sockfd, "GRAPHIC\n", 9, 0) < 0)
	std::cout << "ERROR: sending cmd GRAPHIC to server failed." << std::endl;
      return (1);
    }
  else if (strncmp(str.c_str(), "msz", 3) == 0)
    this->parseSizeMap(str);
  else if (strncmp(str.c_str(), "tna", 3) == 0)
    this->parseTna(str);
  else if (strncmp(str.c_str(), "ppo", 3) == 0)
    this->parsePpo(str);
  else if (strncmp(str.c_str(), "pnw", 3) == 0)
    this->parsePnw(str);
  else if (strncmp(str.c_str(), "bct", 3) == 0)
    this->parseBct(str);
  else if (strncmp(str.c_str(), "seg", 3) == 0)
    this->parseSeg(str);
  else
    return (-1);
  return (0);
}

// Setters

void		ParseSend::setSockFd(int fdsock)
{
  this->_sockfd = fdsock;
}

void		ParseSend::setMap(Map *map)
{
  this->_map = map;
}

void		ParseSend::setLib(Graphical *lib)
{
  this->_lib = lib;
}

// Getters

int		ParseSend::getMapX() const
{
  return this->_mapX;
}

int		ParseSend::getMapY() const
{
  return this->_mapY;
}
