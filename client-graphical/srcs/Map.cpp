//
// Map.cpp for Map cpp in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 25 15:03:37 2017 
// Last update Sun Jul  2 15:58:17 2017 
//

# include "Map.hh"
# include <iostream>

Map::Map() : _map()
{
}

Map::Map(int x, int y) : _map()
{
  std::cout << "init map size " << x << "/" << y << std::endl;
  this->_x = x;
  this->_y = y;
  initMap();
}

Map::~Map()
{
}


void					Map::initMap()
{
  for (size_t j = 0; j < (size_t)this->_x; j++)
    {
      _map.push_back(std::vector<Case *>());
      for (size_t i = 0; i < (size_t)this->_y; i++)
	{
	  _map[j].push_back(new Case(j, i));
	}
    }
}

// Getters

std::vector< std::vector< Case*> >	Map::getMap() const
{
  return this->_map;
}

Case					*Map::getCase(const int &x, const int &y)
{
  return this->_map[y][x];
}

int					Map::getX() const
{
  return this->_x;
}

int					Map::getY() const
{
  return this->_y;
}

// Setters

void					Map::setMap(std::vector< std::vector< Case*> > map)
{
  this->_map = map;
}

void					Map::setX(int x)
{
  this->_x = x;
}

void					Map::setY(int y)
{
  this->_y = y;
}
