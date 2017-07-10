//
// Client.cpp for  in /home/elodie/C/reseau/Zappy/client/srcs
// 
// Made by Elodie
// Login   <elodie>
// 
// Started on  Wed Jun  7 12:03:22 2017 Elodie
// Last update Wed Jun  7 12:08:04 2017 Elodie
//

#include "Client.hpp"

Client::Client()
{
  this->machine = "localhost";
}

Client::Client(const int &port, const std::string &team, const std::string machine)
{
  this->port = port;
  this->team = team;
  this->machine = machine;
}

Client::Client(const int &port, const std::string &team)
{
  this->port = port;
  this->team = team;
  this->machine = "localhost";
}

Client::Client(const Client &client)
{
  this->port = client.getPort();
  this->team = client.getTeam();
  this->machine = client.getMachine();
}

Client::~Client(){}

void			Client::setPort(const int &port)
{
  this->port = port;
}

void			Client::setTeam(const std::string &team)
{
  this->team = team;
}

void			Client::setMachine(const std::string &machine)
{
  this->machine = machine;
}

int			Client::getPort() const
{
  return this->port;
}

std::string		Client::getTeam() const
{
  return this->team;
}

std::string		Client::getMachine() const
{
  return this->machine;
}

Connexion		&Client::operator=(const Client &client)
{
  this->port = client.getPort();
  this->team = client.getTeam();
  this->machine = client.getMachine();  
}
