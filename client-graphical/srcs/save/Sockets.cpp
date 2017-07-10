//
// Sockets.cpp for  in /home/elodie/C/reseau/Zappy/client/srcs
// 
// Made by Elodie
// Login   <elodie>
// 
// Started on  Wed Jun  7 16:10:35 2017 Elodie
// Last update Mon Jun 26 18:08:02 2017 
//

#include "Sockets.hpp"

Sockets::Sockets(){}

Sockets::Sockets(const int &port, const std::string &team, const std::string &machine)
{
  this->port = port;
  this->team = team;
  this->machine = machine;
}

Sockets::Sockets(const Sockets &sock)
{
  (void)sock;
}

Sockets::~Sockets(){}

void		Sockets::setPort(const int &port)
{
  this->port = port;
}

void		Sockets::setTeam(const std::string &team)
{
  this->team = team;
}

void		Sockets::setMachine(const std::string &machine)
{
  this->machine = machine;
}

void		Sockets::setAddr(struct sockaddr_in addr)
{
  (void)addr;
}

int		Sockets::getPort() const
{
  return this->port;
}

std::string	Sockets::getTeam() const
{
  return this->team;
}

std::string	Sockets::getMachine() const
{
  return this->machine;
}

struct sockaddr_in	Sockets::getAddr() const
{
  return this->addr;
}

int		Sockets::getSockfd() const
{
  return this->sockfd;
}

int		Sockets::Connect()
{
  if (this->initSock() == 1)
    return 1;
  this->fillAddr();
  if (this->connectSock() == 1)
    return 1;
  return 0;
}

int		Sockets::initSock()
{
  int		opt = 1;

  this->sockfd = socket(PF_INET, SOCK_STREAM, 0);
  if (this->sockfd == -1)
    return 1;
  setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  return 0;
}

void		Sockets::fillAddr()
{
  memset(&addr, 0, sizeof(struct sockaddr_in));
  addr.sin_family = PF_INET;
  addr.sin_port = htons(this->port);
  addr.sin_addr.s_addr = inet_addr(this->machine.c_str());
}

int		Sockets::connectSock()
{
  unsigned int	len_t = sizeof(const struct sockaddr);

  if ((connect(this->sockfd, (const struct sockaddr *)&addr, len_t)) == -1)
    return 1;
  return 0;
}
