//
// Parse.hh for Parse in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Thu Jun 29 09:44:09 2017 
// Last update Sun Jul  2 19:47:50 2017 
//

#pragma once

# include <iostream>
# include <istream>
# include <sstream>
# include <string>
# include <cstring>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>

# include "All.hh"
# include "Map.hh"
# include "Case.hh"
# include "Graphical.hh"

class ParseSend
{

private:

  Map		*_map;
  Graphical	*_lib;
  int		_sockfd;
  int		_mapX;
  int		_mapY;
  
public:
  
  ParseSend(int socketFd);
  ~ParseSend();

  int		checkReaded(std::string str);

  // Parse cmds
  
  void		parseSizeMap(std::string str);
  void		parseSeg(std::string str);
  void		parsePpo(std::string str);
  void		parsePnw(std::string str);
  void		parsePlv(std::string str);
  void		parsePin(std::string str);
  void		parsePdi(std::string str);
  void		parseBct(std::string str);
  void		parseTna(std::string str);
  
  // Send cmds

  void		sendMsz();
  void		sendMct();
  void		sendSqt();
  void		sendTna();
  
  // Setters
  
  void		setSockFd(int fdsock);
  void		setMap(Map *map);
  void		setLib(Graphical *lib);

  // Getters

  int		getMapX() const;
  int		getMapY() const;
};
