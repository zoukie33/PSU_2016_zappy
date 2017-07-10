//
// Case.hh for Case hh in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 25 18:05:15 2017 
// Last update Sun Jul  2 11:18:00 2017 
//

#pragma once

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

class   Case
{

private:

//CASE
  int         _x;
  int         _y;
  sf::Texture _texture;
  sf::Sprite  _sprite;

//LINEMATE
  int		      _linemate;
  int         _linematePosX;
  int         _linematePosY;  
  sf::Texture _linemateTexture;
  sf::Sprite  _linemateSprite;

//DERAUMERE
  int		      _deraumere;
  int         _deraumerePosX;
  int         _deraumerePosY;    
  sf::Texture _deraumereTexture;
  sf::Sprite  _deraumereSprite;

//SIBUR
  int		      _sibur;
  int         _siburPosX;
  int         _siburPosY;  
  sf::Texture _siburTexture;
  sf::Sprite  _siburSprite;

//MENDIANE
  int		      _mendiane;
  int         _mendianePosX;
  int         _mendianePosY;  
  sf::Texture _mendianeTexture;
  sf::Sprite  _mendianeSprite;

//PHIRAS
  int		      _phiras;
  int         _phirasPosX;
  int         _phirasPosY;  
  sf::Texture _phirasTexture;
  sf::Sprite  _phirasSprite;

//THYSTAME
  int		      _thystame;
  int         _thystamePosX;
  int         _thystamePosY;  
  sf::Texture _thystameTexture;
  sf::Sprite  _thystameSprite;

  //FOOD
  int         _food;
  int         _foodPosX;
  int         _foodPosY;
  sf::Texture _foodTexture;
  sf::Sprite  _foodSprite;
  
public:

  Case(int x, int y);
  ~Case();
  
  //SETTERS
  void        setPos(int x, int y);
  void        setTextureOnSprite(sf::Texture newTexture);

  //GETTERS
  int         getPosX();
  int         getPosY();
  sf::Sprite  getSprite();
  sf::Texture getTexture();

  //LINEMATE
  void	      setLinemate(int linemate);
  void        setLinematePos(int x, int y);
  void        setLinemateTexture();

  int         getLinemate();
  int         getLinematePosX();
  int         getLinematePosY();
  sf::Sprite  getLinemateSprite();
  sf::Texture getLinemateTexture();

  //DEBRAUMERE
  void	      setDeraumere(int deraumere);
  void        setDeraumerePos(int x, int y);
  void        setDeraumereTexture();

  int         getDeraumere();
  int         getDeraumerePosX();
  int         getDeraumerePosY();
  sf::Sprite  getDeraumereSprite();
  sf::Texture getDeraumereTexture();

  //SIBUR
  void	      setSibur(int sibur);
  void        setSiburPos(int x, int y);
  void        setSiburTexture();

  int         getSibur();
  int         getSiburPosX();
  int         getSiburPosY();
  sf::Sprite  getSiburSprite();
  sf::Texture getSiburTexture();

  //MENDIANE
  void	      setMendiane(int mendiane);
  void        setMendianePos(int x, int y);
  void        setMendianeTexture();

  int         getMendiane();
  int         getMendianePosX();
  int         getMendianePosY();
  sf::Sprite  getMendianeSprite();
  sf::Texture getMendianeTexture();

  //PHIRAS
  void	      setPhiras(int phiras);
  void        setPhirasPos(int x, int y);
  void        setPhirasTexture();

  int         getPhiras();
  int         getPhirasPosX();
  int         getPhirasPosY();
  sf::Sprite  getPhirasSprite();
  sf::Texture getPhirasTexture();

  //THYSTAME
  void	      setThystame(int thystame);
  void        setThystamePos(int x, int y);
  void        setThystameTexture();

  int         getThystame();
  int         getThystamePosX();
  int         getThystamePosY();
  sf::Sprite  getThystameSprite();
  sf::Texture getThystameTexture();

  //FOOD

  void	      setFood(int food);
  void        setFoodPos(int x, int y);
  void        setFoodTexture();

  int         getFood();
  int         getFoodPosX();
  int         getFoodPosY();
  sf::Sprite  getFoodSprite();
  sf::Texture getFoodTexture();

  
};
