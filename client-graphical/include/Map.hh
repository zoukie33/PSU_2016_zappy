//
// Map.hh for Map hh in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 25 18:23:19 2017 
// Last update Sun Jul  2 15:58:27 2017 
//

#pragma once

# include "Case.hh"
# include <vector>

class   Map
{

private:

  int					_x;
  int					_y;
  std::vector< std::vector< Case *> >	_map;    
  
public:

  Map();
  Map(int x, int y);
  ~Map();

  void					initMap();
  
  // Getters
  
  std::vector< std::vector< Case *> >	getMap() const;
  int					getX() const;
  int					getY() const;
  Case					*getCase(const int &X, const int &Y);

  // Setters
  
  void					setX(int x);
  void					setY(int y);
  void					setMap(std::vector< std::vector< Case *> > map);
};
