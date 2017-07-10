//
// Parse.hh for Parse in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Thu Jun 29 09:44:09 2017 
// Last update Thu Jun 29 13:20:22 2017 
//

#pragma once

# include <iostream>
# include <string>
# include <cstring>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>

class ParseSend
{

private:

  int		_sockfd;
  int		_mapX;
  int		_mapY;
  
public:
  
  ParseSend(int socketFd);
  ~ParseSend();

  int		checkReaded(std::string str);

  // Parse cmds
  
  void		parseSizeMap(std::string str);
  void		parsePpo(std::string str);
  void		parsePlv(std::string str);
  void		parsePin(std::string str);
  
  // Send cmds

  void		sendTeamName(std::string str);
  void		sendMsz();
  void		sendMct();
  void		sendSqt();
  void		sendTna();
  
  // Setters
  
  void		setSockFd(int fdsock);

  // Getters

  int		getMapX() const;
  int		getMapY() const;
};
