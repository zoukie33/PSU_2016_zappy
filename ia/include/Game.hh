//
// Game.hh for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:17:29 2017
// Last update Thu Jun 29 19:11:38 2017 Bourreau Quentin
//

#pragma once

# include <sys/types.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <string.h>
# include <stdio.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <net/if.h>
# include <netdb.h>
# include <string>
# include <iostream>
# include <vector>

# include "Player.hh"
# include "ParseSend.hh"

class	Game
{

private:

  int			_port;
  int			_sockfd;
  std::string		_team;
  std::string		_ip;
  struct sockaddr_in	_addr;
  struct hostent	*_hostinfo;

  Player		*_ia;

public:

  Game(const int &port, const std::string &teamName, const std::string &ip);
  ~Game();

  int			connectToServer();
  int			selecting();
  int			boucle();
  std::string		readServer();
  void			parseThePositionPlayer(std::string);

  // Setters

  void			setPort(const int &port);
  void			setIp(const std::string &ip);
  void			setTeam(const std::string &teamName);
  void			setAddr(struct sockaddr_in addr);
  void			setIa(Player &ia);

  // Getter

  int			getPort() const;
  std::string		getIp() const;
  std::string		getTeam() const;
  struct sockaddr_in	getAddr() const;
  int			getSockFd() const;
  Player		*getIa() const;
};
