# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

class   Player
{
private:
    int         _x;
    int         _y;
    int         _orientation;
    int         _select;
    int         _team;
    int         _level;
    int         _id;
    sf::Texture _playerTexture;
    sf::Sprite  _playerSprite;

    int         _food;
    int         _linemate;
    int         _deraumere;
    int         _sibur;
    int         _mendiane;
    int         _phiras;
    int         _thystame;

public:
    Player(int id, int x, int y, int orientation, int level, int team);
    ~Player();

    int         getPlayerPosX();
    int         getPlayerPosY();
    void        setPlayerPos(int x, int y);
    void        setPlayerFace();
    void        setPlayerBack();
    void        setPlayerRight();
    void        setPlayerLeft();
    sf::Sprite  getPlayerSprite();
    sf::Texture getPlayerTexture();

    int         getFood();
    int         getLinemate();
    int         getDeraumere();
    int         getSibur();
    int         getMendiane();
    int         getPhiras();
    int         getThystame();

    void        isSelect();
    void        isNotSelect();
    int         getSelect();
    void        setOrientation(int orientation);
    int         getOrientation();
    int         getId();
    void        Move(int x, int y, int orientation);
    void        setLevel(int level);
    int         getLevel();
    void        setInventory(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame);
};
