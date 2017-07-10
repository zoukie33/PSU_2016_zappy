//
// Case.cpp for case cpp in /home/zoukie/Desktop/epitech/PSU_2016_zappy/client/srcs
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 25 17:50:46 2017 
// Last update Sun Jul  2 13:20:42 2017 
//

# include <iostream>
# include "Case.hh"

Case::Case(int x, int y)
{
    this->_x = (x * 80) + 400;
    this->_y = y * 80;
    if (!this->_texture.loadFromFile("media/herbe.jpg" ,sf::IntRect(10, 10, 80, 80)))
        std::cout << "Error texture" << std::endl;
    this->setFood(0);
    this->setLinemate(0);
    this->setDeraumere(0);
    this->setSibur(0);
    this->setMendiane(0);
    this->setPhiras(0);
    this->setThystame(0);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setPosition(sf::Vector2f(_x, _y));
    this->setFoodTexture();
    this->setFoodPos(10, 2);
    this->setLinemateTexture();
    this->setLinematePos(40, 15);
    this->setDeraumereTexture();
    this->setDeraumerePos(60, 15);
    this->setSiburTexture();
    this->setSiburPos(18, 40);
    this->setMendianeTexture();
    this->setMendianePos(38, 40);
    this->setPhirasTexture();
    this->setPhirasPos(60, 40);
    this->setThystameTexture();
    this->setThystamePos(25, 60);
}

Case::~Case()
{

}

void    Case::setPos(int x, int y)
{
    this->_x = x;
    this->_y = y;
    this->_sprite.setPosition(sf::Vector2f(_x, _y));    
}

void    Case::setTextureOnSprite(sf::Texture newTexture)
{
    this->_sprite.setTexture(newTexture);
}

int     Case::getPosX()
{
    return this->_x;
}

int     Case::getPosY()
{
    return this->_y;
}

sf::Sprite  Case::getSprite()
{
    return this->_sprite;
}

sf::Texture Case::getTexture()
{
    return this->_texture;
}


//LINEMATE


void    Case::setLinemate(int linemate)
{
    this->_linemate = linemate;
}

void    Case::setLinematePos(int x, int y)
{
    this->_linematePosX = x;
    this->_linematePosY = y;
    this->_linemateSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setLinemateTexture()
{
    if (!this->_linemateTexture.loadFromFile("media/linemate.png" ,sf::IntRect(10, 10, 50, 50)))
        std::cout << "Error texture" << std::endl;
    this->_linemateSprite.setTexture(this->_linemateTexture);
}

int     Case::getLinematePosX()
{
    return this->_linematePosX;
}

int     Case::getLinematePosY()
{
    return this->_linematePosY;
}

sf::Sprite  Case::getLinemateSprite()
{
    return this->_linemateSprite;
}

sf::Texture Case::getLinemateTexture()
{
    return this->_linemateTexture;
}


//DERAUMERE


void    Case::setDeraumere(int deraumere)
{
    this->_deraumere = deraumere;
}

void    Case::setDeraumerePos(int x, int y)
{
    this->_deraumerePosX = x;
    this->_deraumerePosY = y;
    this->_deraumereSprite.setPosition(sf::Vector2f(x + this->_x, y + this->_y));
}

void    Case::setDeraumereTexture()
{
    this->_deraumereTexture.loadFromFile("media/deraumere.png" ,sf::IntRect(10, 10, 20, 20));
    this->_deraumereSprite.setTexture(this->_deraumereTexture);
}

int     Case::getDeraumerePosX()
{
    return this->_deraumerePosX;
}

int     Case::getDeraumerePosY()
{
    return this->_deraumerePosY;
}

sf::Sprite  Case::getDeraumereSprite()
{
    return this->_deraumereSprite;
}

sf::Texture Case::getDeraumereTexture()
{
    return this->_deraumereTexture;
}


//SIBUR


void    Case::setSibur(int sibur)
{
    this->_sibur = sibur;
}

void    Case::setSiburPos(int x, int y)
{
    this->_siburPosX = x;
    this->_siburPosY = y;
    this->_siburSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setSiburTexture()
{
    this->_siburTexture.loadFromFile("media/sibur.png" ,sf::IntRect(10, 10, 50, 50));
    this->_siburSprite.setTexture(this->_siburTexture);
}

int     Case::getSiburPosX()
{
    return this->_siburPosX;
}

int     Case::getSiburPosY()
{
    return this->_siburPosY;
}

sf::Sprite  Case::getSiburSprite()
{
    return this->_siburSprite;
}

sf::Texture Case::getSiburTexture()
{
    return this->_siburTexture;
}


//MENDIANE


void    Case::setMendiane(int mendiane)
{
    this->_mendiane = mendiane;
}

void    Case::setMendianePos(int x, int y)
{
    this->_mendianePosX = x;
    this->_mendianePosY = y;
    this->_mendianeSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setMendianeTexture()
{
    this->_mendianeTexture.loadFromFile("media/mendiane.png" ,sf::IntRect(10, 10, 50, 50));
    this->_mendianeSprite.setTexture(this->_mendianeTexture);
}

int     Case::getMendianePosX()
{
    return this->_mendianePosX;
}

int     Case::getMendianePosY()
{
    return this->_mendianePosY;
}

sf::Sprite  Case::getMendianeSprite()
{
    return this->_mendianeSprite;
}

sf::Texture Case::getMendianeTexture()
{
    return this->_mendianeTexture;
}


//PHIRAS

void    Case::setPhiras(int phiras)
{
    this->_phiras = phiras;
}

void    Case::setPhirasPos(int x, int y)
{
    this->_phirasPosX = x;
    this->_phirasPosY = y;
    this->_phirasSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setPhirasTexture()
{
    this->_phirasTexture.loadFromFile("media/phiras.png" ,sf::IntRect(10, 10, 50, 50));
    this->_phirasSprite.setTexture(this->_phirasTexture);
}

int     Case::getPhirasPosX()
{
    return this->_phirasPosX;
}

int     Case::getPhirasPosY()
{
    return this->_phirasPosY;
}

sf::Sprite  Case::getPhirasSprite()
{
    return this->_phirasSprite;
}

sf::Texture Case::getPhirasTexture()
{
    return this->_phirasTexture;
}


//THYSTAME

void    Case::setThystame(int thystame)
{
    this->_thystame = thystame;
}

void    Case::setThystamePos(int x, int y)
{
    this->_thystamePosX = x;
    this->_thystamePosY = y;
    this->_thystameSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setThystameTexture()
{
    this->_thystameTexture.loadFromFile("media/thystame.png" ,sf::IntRect(10, 10, 50, 50));
    this->_thystameSprite.setTexture(this->_thystameTexture);
}

int     Case::getThystamePosX()
{
    return this->_thystamePosX;
}

int     Case::getThystamePosY()
{
    return this->_thystamePosY;
}

sf::Sprite  Case::getThystameSprite()
{
    return this->_thystameSprite;
}

sf::Texture Case::getThystameTexture()
{
    return this->_thystameTexture;
}


//FOOD

void    Case::setFood(int food)
{
    this->_food = food;
}

void    Case::setFoodPos(int x, int y)
{
    this->_foodPosX = x;
    this->_foodPosY = y;
    this->_foodSprite.setPosition(sf::Vector2f(this->_x + x, this->_y + y));
}

void    Case::setFoodTexture()
{
    this->_foodTexture.loadFromFile("media/food.png", sf::IntRect(10, 10, 50, 50));
    this->_foodSprite.setTexture(this->_foodTexture);
}

int     Case::getFoodPosX()
{
    return this->_foodPosX;
}

int     Case::getFoodPosY()
{
    return this->_foodPosY;
}

sf::Sprite  Case::getFoodSprite()
{
    return this->_foodSprite;
}

sf::Texture Case::getFoodTexture()
{
    return this->_foodTexture;
}

int     Case::getFood()
{
    return this->_food;
}

int     Case::getLinemate()
{
    return this->_linemate;
}

int     Case::getDeraumere()
{
    return this->_deraumere;
}

int     Case::getSibur()
{
    return this->_sibur;
}

int     Case::getMendiane()
{
    return this->_mendiane;
}

int     Case::getPhiras()
{
    return this->_phiras;
}

int     Case::getThystame()
{
    return this->_thystame;
}