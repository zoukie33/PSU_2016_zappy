//
// Graphical.hh for Graphical in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sat Jun 24 17:58:28 2017 
// Last update Fri Jun 30 17:58:27 2017 
//

#pragma once

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>

# include "All.hh"
# include "Map.hh"

class	Graphical
{
  
private:
  
  sf::RenderWindow			_window;
  Map					*_map;
  sf::Text				_inventaire;
  sf::Text        _food;
  sf::Text        _food_nb;
  sf::Text				_linemate;
  sf::Text				_linemate_nb;
  sf::Text				_deraumere;
  sf::Text				_deraumere_nb;
  sf::Text				_sibur;
  sf::Text				_sibur_nb;
  sf::Text				_mendiane;
  sf::Text				_mendiane_nb;
  sf::Text				_phiras;
  sf::Text				_phiras_nb;
  sf::Text				_thystame;
  sf::Text				_thystame_nb;
  sf::Text        _team;
  sf::Text        _team_name;
  sf::Font				_font;
  std::string     _teamName;
  std::vector< std::vector< Case* > >	_theMap;

  
public:
  
  Graphical();
  ~Graphical();
  
  bool					isOpen();
  int					  drawAllMap(Case *inv);
  void          DrawRessources(int i, int j);
  void          DrawInventaire(Case * inv);
  void					EventLoop();
  void					clear();
  void					display();
  void          AddNewPlayer();
  void          MovePlayer(int id_player);
  void          ChangePlayerLevel(int id_player);
  void          ChangePlayerInventory(int id_player);
  void          CatchKey();

  // Setters

  void					setMap(Map *theMap);
  void					setMapX(int x);
  void					setMapY(int y);
  void					setGUI(Player *player);
  void          setGUIBase();
  void          setTeamName(std::string team);

  // Getters

  Map					  *getMap() const;
  void					getTheMap(std::vector< std::vector< Case* > > theMap);
};
