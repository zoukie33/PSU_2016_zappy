//
// Graphical.cpp for Graphical cpp in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sat Jun 24 18:36:13 2017 
// Last update Sun Jul  2 20:33:22 2017 
//

# include <iostream>
# include <stdlib.h>
# include <sstream>
# include "Graphical.hh"

Graphical::Graphical()
{
  _window.create(sf::VideoMode(1880, 1100), "Zappy");
}

Graphical::~Graphical()
{
 
}

int			Graphical::drawAllMap(Case *inv)
{
  _theMap = this->_map->getMap();
  this->EventLoop();
  this->clear();
    for (size_t i = 0; i < _theMap.size(); i++)
      for (size_t j = 0; j < _theMap[i].size(); j++)
      {
	      this->_window.draw(_theMap[i][j]->getSprite());
        this->DrawRessources(i, j);
      }
  this->DrawInventaire(inv);
  for (size_t ipl = 0; ipl < PlayersList.size(); ipl++){
    this->setGUI(PlayersList[ipl]);
    this->_window.draw(PlayersList[ipl]->getPlayerSprite());
  }
  this->_window.display();
  return (0);
}

bool			Graphical::isOpen()
{
  return _window.isOpen();
}

void			Graphical::EventLoop()
{
    sf::Event		event;

    while (_window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::KeyPressed)
            this->CatchKey();
    }
}

void			Graphical::clear()
{
    _window.clear(sf::Color::Black);
}

void			Graphical::display()
{
    _window.display();
}


// Setters

void			Graphical::setMap(Map *theMap)
{
  this->_map = theMap;
}

void			Graphical::setMapX(int x)
{
  this->_map->setX(x);
}

void			Graphical::setMapY(int y)
{
  this->_map->setY(y);
}

// Getters

Map			*Graphical::getMap() const
{
  return _map;
}

void	Graphical::getTheMap(std::vector< std::vector< Case* > > theMap)
{
  this->_theMap = theMap;
}

std::string IntToString ( int number )
{
  std::ostringstream oss;
  oss<< number;
  return oss.str();
}

void    Graphical::setGUI(Player *player)
{
  std::string str;

  str = IntToString(player->getFood());  
  this->_food_nb.setString(str);

  str = IntToString(player->getLinemate());  
  this->_linemate_nb.setString(str);

  str = IntToString(player->getDeraumere());  
  this->_deraumere_nb.setString(str);

  str = IntToString(player->getSibur());  
  this->_sibur_nb.setString(str);

  str = IntToString(player->getMendiane());  
  this->_mendiane_nb.setString(str);

  str = IntToString(player->getPhiras());  
  this->_phiras_nb.setString(str);

  str = IntToString(player->getThystame());  
  this->_thystame_nb.setString(str);

  this->setTeamName("Nom de la team");
  this->_team_name.setString(_teamName);
}

void    Graphical::setGUIBase()
{
  std::string str = IntToString(0);  
  if (!this->_font.loadFromFile("media/arial.ttf"))
    return;
  this->_inventaire.setFont(this->_font);
  this->_inventaire.setString("Inventaire");
  this->_inventaire.setCharacterSize(24);
  this->_inventaire.setColor(sf::Color::White);
  this->_inventaire.setPosition(150, 20);
  this->_inventaire.setStyle(sf::Text::Bold | sf::Text::Underlined);

  this->_food.setFont(this->_font);
  this->_food.setString("Food : ");
  this->_food.setCharacterSize(24);
  this->_food.setColor(sf::Color::White);
  this->_food.setPosition(150, 80);

  this->_food_nb.setFont(this->_font);
  this->_food_nb.setString(str);
  this->_food_nb.setCharacterSize(24);
  this->_food_nb.setColor(sf::Color::White);
  this->_food_nb.setPosition(300, 80);

  this->_linemate.setFont(this->_font);
  this->_linemate.setString("Linemate : ");
  this->_linemate.setCharacterSize(24);
  this->_linemate.setColor(sf::Color::White);
  this->_linemate.setPosition(150, 120);

  this->_linemate_nb.setFont(this->_font);
  this->_linemate_nb.setString(str);
  this->_linemate_nb.setCharacterSize(24);
  this->_linemate_nb.setColor(sf::Color::White);
  this->_linemate_nb.setPosition(300, 120);

  this->_deraumere.setFont(this->_font);
  this->_deraumere.setString("Deraumere : ");
  this->_deraumere.setCharacterSize(24);
  this->_deraumere.setColor(sf::Color::White);
  this->_deraumere.setPosition(150, 160);

  this->_deraumere_nb.setFont(this->_font);
  this->_deraumere_nb.setString(str);
  this->_deraumere_nb.setCharacterSize(24);
  this->_deraumere_nb.setColor(sf::Color::White);
  this->_deraumere_nb.setPosition(300, 160);

  this->_sibur.setFont(this->_font);
  this->_sibur.setString("Sibur : ");
  this->_sibur.setCharacterSize(24);
  this->_sibur.setColor(sf::Color::White);
  this->_sibur.setPosition(150, 200);

  this->_sibur_nb.setFont(this->_font);
  this->_sibur_nb.setString(str);
  this->_sibur_nb.setCharacterSize(24);
  this->_sibur_nb.setColor(sf::Color::White);
  this->_sibur_nb.setPosition(300, 200);

  this->_mendiane.setFont(this->_font);
  this->_mendiane.setString("Mendiane : ");
  this->_mendiane.setCharacterSize(24);
  this->_mendiane.setColor(sf::Color::White);
  this->_mendiane.setPosition(150, 240);

  this->_mendiane_nb.setFont(this->_font);
  this->_mendiane_nb.setString(str);
  this->_mendiane_nb.setCharacterSize(24);
  this->_mendiane_nb.setColor(sf::Color::White);
  this->_mendiane_nb.setPosition(300, 240);

  this->_phiras.setFont(this->_font);
  this->_phiras.setString("Phiras : ");
  this->_phiras.setCharacterSize(24);
  this->_phiras.setColor(sf::Color::White);
  this->_phiras.setPosition(150, 280);

  this->_phiras_nb.setFont(this->_font);
  this->_phiras_nb.setString(str);
  this->_phiras_nb.setCharacterSize(24);
  this->_phiras_nb.setColor(sf::Color::White);
  this->_phiras_nb.setPosition(300, 280);

  this->_thystame.setFont(this->_font);
  this->_thystame.setString("Thystame : ");
  this->_thystame.setCharacterSize(24);
  this->_thystame.setColor(sf::Color::White);
  this->_thystame.setPosition(150, 320);

  this->_thystame_nb.setFont(this->_font);
  this->_thystame_nb.setString(str);
  this->_thystame_nb.setCharacterSize(24);
  this->_thystame_nb.setColor(sf::Color::White);
  this->_thystame_nb.setPosition(300, 320);

  this->_team.setFont(this->_font);
  this->_team.setString("Team");
  this->_team.setCharacterSize(24);
  this->_team.setColor(sf::Color::White);
  this->_team.setPosition(180, 400);
  this->_team.setStyle(sf::Text::Bold | sf::Text::Underlined);

  this->setTeamName("Nom de la team");
  this->_team_name.setFont(this->_font);
  this->_team_name.setString(_teamName);
  this->_team_name.setCharacterSize(24);
  this->_team_name.setColor(sf::Color::White);
  this->_team_name.setPosition(120, 440);
}

void  Graphical::setTeamName(std::string team)
{
  this->_teamName = team;
}

void  Graphical::DrawRessources(int i, int j)
{
  if (_theMap[i][j]->getFood() > 0)        
    this->_window.draw(_theMap[i][j]->getFoodSprite());
  if (_theMap[i][j]->getLinemate() > 0)        
    this->_window.draw(_theMap[i][j]->getLinemateSprite());
  if (_theMap[i][j]->getDeraumere() > 0)        
    this->_window.draw(_theMap[i][j]->getDeraumereSprite());
  if (_theMap[i][j]->getSibur() > 0)        
    this->_window.draw(_theMap[i][j]->getSiburSprite());
  if (_theMap[i][j]->getMendiane() > 0)        
    this->_window.draw(_theMap[i][j]->getMendianeSprite());
  if (_theMap[i][j]->getPhiras() > 0)        
    this->_window.draw(_theMap[i][j]->getPhirasSprite());
  if (_theMap[i][j]->getThystame() > 0)        
    this->_window.draw(_theMap[i][j]->getThystameSprite());
}

void  Graphical::DrawInventaire(Case *inv)
{
  this->_window.draw(this->_inventaire);
  inv->setFoodPos(-370,-5);
  this->_window.draw(inv->getFoodSprite());
  this->_window.draw(this->_food);
  this->_window.draw(this->_food_nb);
  inv->setLinematePos(-365,50);
  this->_window.draw(inv->getLinemateSprite());
  this->_window.draw(this->_linemate);
  this->_window.draw(this->_linemate_nb);  
  inv->setDeraumerePos(-365,90);
  this->_window.draw(inv->getDeraumereSprite());  
  this->_window.draw(this->_deraumere);
  this->_window.draw(this->_deraumere_nb); 
  inv->setSiburPos(-365,130);
  this->_window.draw(inv->getSiburSprite());   
  this->_window.draw(this->_sibur);
  this->_window.draw(this->_sibur_nb);
  inv->setMendianePos(-365,170);
  this->_window.draw(inv->getMendianeSprite()); 
  this->_window.draw(this->_mendiane);
  this->_window.draw(this->_mendiane_nb);   
  inv->setPhirasPos(-365,210);
  this->_window.draw(inv->getPhirasSprite()); 
  this->_window.draw(this->_phiras);
  this->_window.draw(this->_phiras_nb);    
  inv->setThystamePos(-365,250);
  this->_window.draw(inv->getThystameSprite()); 
  this->_window.draw(this->_thystame);    
  this->_window.draw(this->_thystame_nb);
  this->setTeamName("Nom de team");
  this->_window.draw(this->_team);
  this->_window.draw(this->_team_name);
}

void  Graphical::AddNewPlayer()
{
  int i = 0;
  int id;
  int x;
  int y;
  int orientation;
  int level;
  int team;
  for (std::list<std::list<int>>::iterator it = Players.begin(); it != Players.end(); ++it){
    for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++){
      if (i == 0)
        id = *it2;
      else if (i == 1)
        x = *it2;
      else if (i == 2)
        y = *it2;
      else if (i == 3)
        orientation = *it2;
      else if (i == 4)
        level = *it2;
      else
        team = *it2;
      i++;
    }
    PlayersList.push_back(new Player(id, x, y, orientation, level, team));
    i = 0;
  }
}

void  Graphical::MovePlayer(int id_player)
{
  int orientation;
  int x;
  int y;
  int i = -1;
  for (std::list<std::list<int>>::iterator it = Players.begin(); it != Players.end(); ++it){
    for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++){
      if (id_player == *it2){
        i = 1;
      }
      if (i > 0){
        if (i == 2)
          x = *it2;
        else if (i == 3)
          y = *it2;
        else if (i == 4)
          orientation = *it2;
        i++;
      }
    }

    for (size_t ipl = 0; ipl < PlayersList.size(); ipl++)
      if (id_player == PlayersList[ipl]->getId())
	PlayersList[ipl]->Move(x, y, orientation);
    i = -1;
  }
}

void  Graphical::ChangePlayerLevel(int id_player)
{
  for (std::list<std::list<int>>::iterator it = PlayersLevels.begin(); it != PlayersLevels.end(); ++it){
    for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++){
      if (id_player == *it2){
        it2++;
        for (size_t ipl = 0; ipl < PlayersList.size(); ipl++)
          if (id_player == PlayersList[ipl]->getId())
	          PlayersList[ipl]->setLevel(*it2);  
      }
    }
  }
}

void  Graphical::ChangePlayerInventory(int id_player)
{
    for (std::list<std::list<int>>::iterator it = PlayersInventorys.begin(); it != PlayersInventorys.end(); ++it){
    for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++){
      if (id_player == *it2){
        it2++;
        for (size_t ipl = 0; ipl < PlayersList.size(); ipl++)
          if (id_player == PlayersList[ipl]->getId())
	          PlayersList[ipl]->setInventory((*it2)+2, (*it2)+3, (*it2)+4, (*it2)+5, (*it2)+6, (*it2)+7, (*it2)+8);
      }
    }
  }
}

void  Graphical::CatchKey()
{
  /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    for (size_t ipl = 0; ipl < PlayersList.size(); ipl++){
      if (PlayersList[ipl]->getSelect() == 1 && PlayersList.size() > ipl){
        PlayersList[ipl]->isNotSelect();
        PlayersList[ipl+1]->isSelect();
	        this->setGUI(PlayersList[ipl+1]);
        check = 1;
      }
    }
    if (check == 0 && PlayersList.size() > 0){
      this->setGUI(PlayersList[0]);
      PlayersList[0]->isSelect();
  }
}*/
}