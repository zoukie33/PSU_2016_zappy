//
// Sockets.hpp for  in /home/elodie/C/reseau/Zappy/client/include
// 
// Made by Elodie
// Login   <elodie>
// 
// Started on  Wed Jun  7 15:55:09 2017 Elodie
// Last update Thu Jun  8 14:33:32 2017 Elodie
//

#ifndef SOCKETS_HPP_
# define SOCKETS_HPP_

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

class	Sockets{

private:
  int			port;
  int			sockfd;
  std::string		team;
  std::string		machine;
  struct sockaddr_in	addr;

public:
  Sockets();
  Sockets(const int &, const std::string &, const std::string &);
  Sockets(const Sockets &);
  ~Sockets();

  void		setPort(const int &);
  void		setTeam(const std::string &);
  void		setMachine(const std::string &);
  void		setAddr(struct sockaddr_in);

  int		getPort() const;
  std::string	getTeam() const;
  std::string	getMachine() const;
  struct sockaddr_in getAddr() const;
  int		getSockfd() const;

  int		Connect();

private:
  int		initSock();
  void		fillAddr();
  int		connectSock();
  
};

#endif
