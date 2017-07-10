//
// Game.cpp for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:24:28 2017
// Last update Fri Jun 30 16:52:15 2017 
//

# include "Game.hh"

Game::Game(const int &port, const std::string &ip)
{
  _port = port;
  _ip = ip;
  if (_ip.empty())
    _ip = "localhost";
  std::cout << "IP = " << _ip << std::endl;
  _lib = new Graphical();
  this->connectToServer();
  _pars = new ParseSend(this->_sockfd);

}

Game::~Game()
{

}

int			Game::boucle()
{
  while (this->_lib->isOpen())
    {
      this->selecting();
      this->_lib->drawAllMap();
    }
  return (0);
}

int			Game::readServer()
{
  size_t	len;
  ssize_t	read;
  char		*str;
  FILE		*fd;

  str = NULL;
  fd = fdopen(this->_sockfd, "r+");
  if ((read = getline(&str, &len, fd)) != -1)
    {
      std::string s(str);
      if (pars->checkReaded(s) == 1)
	{
	  std::cout << "hello" << std::endl;
	}
      else if (pars->checkReaded(s) == 2)
	{
	  Map *map = new Map(pars->getMapX(), pars->getMapY()); 
	  this->_lib->setMap(map);
	}
    }  
  delete pars;
  return (0);
}

int			Game::connectToServer()
{
  this->_sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
  FD_SET(this->_sockfd, &readfds);
  if ((ret = select(this->_sockfd + 1, &readfds, NULL, NULL, &tv)) < 0)
    {
      std::cout << "Select failed" << std::endl;
      return (-1);
    }
  if (FD_ISSET(this->_sockfd, &readfds))
    this->readServer();
  return (0);
}
				    
// Setters

void			Game::setPort(const int &port)
{
  _port = port;
}

void			Game::setIp(const std::string &ip)
{
  _ip = ip;
}

void			Game::setAddr(struct sockaddr_in addr)
{
  _addr = addr;
}

void			Game::setGraphical(Graphical &lib)
{
  _lib = &lib;
}

void			Game::setParseSend(ParseSend &pars)
{
  _pars = &pars;
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

struct sockaddr_in	Game::getAddr() const
{
  return _addr;
}

int			Game::getSockFd() const
{
  return _sockfd;
}

Graphical		*Game::getGraphical() const
{
  return _lib;
}

ParseSend		*Game::getParseSend() const
{
  return _lib;
}
