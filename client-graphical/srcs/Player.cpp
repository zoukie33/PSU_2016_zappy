# include "Player.hh"

# include <iostream>

Player::Player(int id, int x, int y, int orientation, int level, int team)
{
    this->setPlayerFace();
    this->setPlayerPos(425, 20);
    this->_x = x;
    this->_y = y;
    this->_food = 0;
    this->_linemate = 0;
    this->_deraumere = 0;
    this->_sibur = 0;
    this->_mendiane = 0;
    this->_phiras = 0;
    this->_thystame = 0;
    this->_select = 0;
    this->_x = 425;
    this->_y = 20;
    this->_orientation = orientation;
    this->_level = level;
    this->_id = id;
    this->_team = team;
}

Player::~Player()
{}

int     Player::getPlayerPosX()
{
    return this->_x;
}

int     Player::getPlayerPosY()
{
    return this->_y;
}

sf::Sprite  Player::getPlayerSprite()
{
    return this->_playerSprite;
}

sf::Texture Player::getPlayerTexture()
{
    return this->_playerTexture;
}

void    Player::setPlayerPos(int x, int y)
{
    this->_x = (80 * x)+425;
    this->_y = (80 * y)+20;
    this->_playerSprite.setPosition(sf::Vector2f(_x, _y));
}

void    Player::setPlayerFace()
{
    this->_playerTexture.loadFromFile("media/tidus_face.png" ,sf::IntRect(1, 1, 50, 50));
    this->_playerSprite.setTexture(this->_playerTexture);
}

void    Player::setPlayerBack()
 {
    this->_playerTexture.loadFromFile("media/tidus_back.png" ,sf::IntRect(1, 1, 50, 50));
    this->_playerSprite.setTexture(this->_playerTexture);
 }

 void   Player::setPlayerRight()
 {
    this->_playerTexture.loadFromFile("media/tidus_right.png" ,sf::IntRect(1, 1, 50, 50));
    this->_playerSprite.setTexture(this->_playerTexture);
 }

 void   Player::setPlayerLeft()
 {
    this->_playerTexture.loadFromFile("media/tidus_left.png" ,sf::IntRect(1, 1, 50, 50));
    this->_playerSprite.setTexture(this->_playerTexture);
 }

 int    Player::getFood()
 {
     return this->_food;
 }

 int    Player::getLinemate()
 {
     return this->_linemate;
 }

 int    Player::getDeraumere()
 {
     return this->_deraumere;
 }

 int    Player::getSibur()
 {
     return this->_sibur;
 }

 int    Player::getMendiane()
 {
     return this->_mendiane;
 }

 int    Player::getPhiras()
 {
     return this->_phiras;
 }

 int    Player::getThystame()
 {
     return this->_thystame;
 }

 void   Player::isSelect()
 {
    this->_select = 1;
    this->_playerSprite.setScale(sf::Vector2f(1.5, 1.5));
 }

 void   Player::isNotSelect()
 {
     this->_select = 0;
     this->_playerSprite.setScale(sf::Vector2f(1, 1));
 }

 int    Player::getSelect()
 {
     return this->_select;
 }

 void   Player::setOrientation(int orientation)
 {
    if (orientation == 1){
        this->_orientation = 1;
        this->setPlayerBack();
    }
    else if (orientation == 2){
        this->_orientation = 2;
        this->setPlayerLeft();
    }
    else if (orientation == 3){
        this->_orientation = 3;
        this->setPlayerFace();
    }
    else if (orientation == 4){
        this->_orientation = 4;
        this->setPlayerRight();
    }
 }

 int    Player::getOrientation()
 {
     return this->_orientation;
 }

 int    Player::getId()
 {
     return this->_id;
 }

 void   Player::Move(int x, int y, int orientation)
 {
     this->setOrientation(orientation);
     this->setPlayerPos(x, y);
 }

 void   Player::setLevel(int level)
 {
     this->_level = level;
 }

 int    Player::getLevel()
 {
     return this->_level;
 }

 void   Player::setInventory(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
 {
     this->_food = food;
     this->_linemate = linemate;
     this->_deraumere = deraumere;
     this->_sibur = sibur;
     this->_mendiane = mendiane;
     this->_phiras = phiras;
     this->_thystame = thystame;

    std::cout << "ONGLEONGLEONGLE !!!!!!" << std::endl;
    std::cout << this->getFood() << std::endl;
    std::cout << this->getLinemate() << std::endl;
    std::cout << this->getDeraumere() << std::endl;
    std::cout << this->getMendiane() << std::endl;
    std::cout << this->getPhiras() << std::endl;
 }