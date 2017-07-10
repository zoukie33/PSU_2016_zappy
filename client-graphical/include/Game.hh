//
// Game.hh for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:17:29 2017
// Last update Sat Jul  1 15:51:17 2017 
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

# include "All.hh"
# include "Graphical.hh"
# include "ParseSend.hh"

class	Game
{

private:

  int			_port;
  int			_sockfd;
  std::string		_ip;
  struct sockaddr_in	_addr;
  struct hostent	*_hostinfo;
  Graphical		*_lib;
  ParseSend		*_pars;

public:

  Game(const int &port, const std::string &ip);
  ~Game();

  int			connectToServer();
  int			selecting();
  int			boucle();
  int			readServer();
  
  // Setters

  void			setPort(const int &port);
  void			setIp(const std::string &ip);
  void			setAddr(struct sockaddr_in addr);
  void			setGraphical(Graphical &lib);
  void			setParseSend(ParseSend &pars);

  // Getter

  int			getPort() const;
  std::string		getIp() const;
  struct sockaddr_in	getAddr() const;
  int			getSockFd() const;
  Graphical		*getGraphical() const;
  ParseSend		*getParseSend() const;

};
