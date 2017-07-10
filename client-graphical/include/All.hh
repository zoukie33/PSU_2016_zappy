//
// All.hh for Game in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Sat Jun 24 17:17:29 2017
// Last update Sun Jul  2 18:27:19 2017 
//

#pragma once

# include <string.h>
# include <list>
# include <vector>

# include "Player.hh"

extern std::list<std::string>		Teams;
extern std::list< std::list<int> >	Players;
extern std::list< std::list<int> >	PlayersLevels;
extern std::list< std::list<int> >	PlayersInventorys;
extern std::vector<Player*>         PlayersList;
