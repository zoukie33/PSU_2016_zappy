// Parse.cpp for Parse cpp in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Thu Jun 29 09:43:35 2017
// Last update Thu Jun 29 19:58:53 2017 Bourreau Quentin
//

# include "ParseSend.hh"

ParseSend::ParseSend(int socketFd)
{
  this->_sockfd = socketFd;
}

ParseSend::~ParseSend()
{

}

void		ParseSend::parsePpo(std::string str)
{
  (void)str; // todo la func - position d'un joueur -
}

void		ParseSend::parsePlv(std::string str)
{
  (void)str; // todo la func - niveau d un joueur -
}

void		ParseSend::parsePin(std::string str)
{
  (void)str; // todo la func - inventaire d un joueur -
}

// Send cmds

void		ParseSend::sendTeamName(std::string str)
{
  str = str + "\n";
  if (send(this->_sockfd, str.c_str(), str.size(), 0) < 0)
    std::cout << "ERROR: sending teamName to server failed." << std::endl;
}

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
  str.resize(str.size() -1);
  std::cout << "checkReaded : str["<< str << "]" << std::endl;
  if (str == "WELCOME" || str == "BIENVENUE")
    return (1);
  return (0);
}

// Setters

void		ParseSend::setSockFd(int fdsock)
{
  this->_sockfd = fdsock;
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
