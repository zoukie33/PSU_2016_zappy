//
// Game.cpp for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:24:28 2017
// Last update Sun Jul  2 19:21:21 2017 
//

# include "Game.hh"
# include <errno.h>
# include <unistd.h>

Game::Game(const int &port, const std::string &ip)
{
  _port = port;
  _ip = ip;
  if (_ip.empty())
    _ip = "localhost";
  std::cout << "IP = " << _ip << std::endl;
  _lib = new Graphical();
  Map *map = new Map();
  _lib->setMap(map);
  this->connectToServer();
  this->_pars = new ParseSend(this->_sockfd);
  this->_pars->setLib(_lib);
}

Game::~Game()
{}

int			Game::boucle()
{
  Case *inv = new Case(1, 1);

  this->_lib->setGUIBase();
  while (this->_lib->isOpen())
    {
      this->selecting();
      this->_lib->drawAllMap(inv);
    }
  return (0);
}

int			Game::readServer()
{
  char	s[4096];

  bzero(s, 4096);
  if (recv(this->_sockfd, s, 4096, 0) < 0)
    std::cout << "Not connected to the server." << std::endl;
  else
    {
      std::istringstream	res;
      std::string		resStr(s);
      std::string		str;
      
      res.str(resStr);
      while(std::getline(res, str, '\n'))
	{
	  std::cout << "[" << str << "]" << std::endl;
	  this->_pars->checkReaded(str);
	}
    }
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

  do
    {
      tv.tv_sec = 0;
      tv.tv_usec = 0;
      FD_ZERO(&readfds);
      FD_SET(this->_sockfd, &readfds);
      if ((ret = select(this->_sockfd + 1, &readfds, NULL, NULL, &tv)) < 0)
	std::cout << "Select failed" << std::endl;
    }
  while(ret == - 1 && errno == EINTR);
  if (ret && FD_ISSET(this->_sockfd, &readfds))
    this->readServer();
  else if (ret == -1)
    std::cout << "ret == - 1" << std::endl;
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
  return _pars;
}
