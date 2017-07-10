//
// Game.cpp for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:24:28 2017
// Last update Sun Jul  2 23:58:09 2017 Bourreau Quentin
//

# include "Game.hh"

Game::Game(const int &port, const std::string &teamName, const std::string &ip)
{
  _port = port;
  _ip = ip;
  if (_ip.empty())
    _ip = "localhost";
  std::cout << "IP = " << _ip << std::endl;
  _team = teamName;
  _ia = new Player(0);
  if ((this->connectToServer()) == -1)
    {
      std::cout << "Unable to connect server " <<  _ip << " port " << _port << " [Connexion refusée]" << std::endl;
      exit(0);
    }
  this->boucle();
}

Game::~Game()
{

}

int			Game::boucle()
{
  std::string	res;
  int		i;

  this->selecting();
  this->_team += "\n";
  dprintf(this->_sockfd, "%s\n", this->_team.c_str());
  res = this->_ia->readServer();
  while (this->_ia->get_dead() == 0)
    {
      i = 0;
      this->_ia->look();
      while (this->_ia->get_look_case(0) != 0)
	{
	  std::cout << "il reste " << this->_ia->get_look_case(0) << " a take" << std::endl;
	  if (this->_ia->get_look_case_ressource(0, 0) != 0)
	    this->_ia->take_food();
	  if (this->_ia->get_look_case_ressource(0, 1) != 0)
	    this->_ia->take_linemate();
	  if (this->_ia->get_look_case_ressource(0, 2) != 0)
	    this->_ia->take_deraumere();
	  if (this->_ia->get_look_case_ressource(0, 3) != 0)
	    this->_ia->take_sibur();
	  if (this->_ia->get_look_case_ressource(0, 4) != 0)
	    this->_ia->take_mendiane();
	  if (this->_ia->get_look_case_ressource(0, 5) != 0)
	    this->_ia->take_phiras();
	  if (this->_ia->get_look_case_ressource(0, 6) != 0)
	    this->_ia->take_thystame();
	  this->_ia->look();
	}
      this->_ia->inventory();
      this->_ia->upgrade_level();
      i = this->_ia->get_direction();
      if (i != 0)
	{
	  if (i == 1)
	    {
	      this->_ia->go_up();
	      this->_ia->turn_left();
	      this->_ia->go_up();
	    }
	  else if (i == 2)
	    this->_ia->go_up();
	  else if (i == 3)
	    {
	      this->_ia->go_up();
	      this->_ia->turn_right();
	      this->_ia->go_up();
	    }
	}
    }
  return (0);
}

std::string	Game::readServer()
{
  size_t	len;
  ssize_t	read;
  char		*str;
  FILE		*fd;
  ParseSend	*pars = new ParseSend(this->_sockfd);
  std::string	res = "";

  str = NULL;
  fd = fdopen(this->_sockfd, "r+");
  if ((read = getline(&str, &len, fd)) == -1)
    exit(0);
  else
    res = str;
  delete pars;
  free(str);
  return (res);
}

int			Game::connectToServer()
{
  this->_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  this->_ia->setFd(this->_sockfd);
  this->_hostinfo = gethostbyname(this->_ip.c_str());
  if (this->_sockfd == -1)
    return (-1);
  if (this->_hostinfo == NULL)
    {
      std::cout << "Unknown host " << this->_ip << std::endl;
      return (-1);
    }
  this->_addr.sin_addr = *(struct in_addr *) this->_hostinfo->h_addr;
  this->_addr.sin_port = htons(this->_port);
  this->_addr.sin_family = AF_INET;
  if (connect(this->_sockfd,(struct sockaddr*) &this->_addr, sizeof(struct sockaddr)) == -1)
    return (-1);
  std::cout << "Connect to server" << std::endl;
  return (0);
}


int			Game::selecting()
{
  int			ret;
  fd_set		readfds;
  struct timeval	tv;

  tv.tv_sec = 1;
  tv.tv_usec = 0;
  FD_ZERO(&readfds);
  if (this->_sockfd != 0)
    FD_SET(this->_sockfd, &readfds);
  if ((ret = select(this->_sockfd + 1, &readfds, (fd_set *) 0, (fd_set *) 0, &tv)) < 0)
    {
      std::cout << "Select failed" << std::endl;
      return (-1);
    }
  if (FD_ISSET(this->_sockfd, &readfds))
    this->_ia->readServer();
  return (0);
}


void			Game::setPort(const int &port)
{
  _port = port;
}

void			Game::setIp(const std::string &ip)
{
  _ip = ip;
}

void			Game::setTeam(const std::string &teamName)
{
  _team = teamName;
}

void			Game::setAddr(struct sockaddr_in addr)
{
  _addr = addr;
}

void			Game::setIa(Player &ia)
{
  _ia = &ia;
}

// Getters

int			Game::getPort() const
{
  return _port;
}

std::string		Game::getIp() const
{
  return _ip;
}

std::string		Game::getTeam() const
{
  return _team;
}

struct sockaddr_in	Game::getAddr() const
{
  return _addr;
}

int			Game::getSockFd() const
{
  return _sockfd;
}

Player			*Game::getIa() const
{
  return _ia;
}
