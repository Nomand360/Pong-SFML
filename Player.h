#ifndef PLAYER_H
#define PLAYER_H
#include <LIBS.h>

enum class Direction{None, Up, Down};

class Player
{
private:
    float speed;
    sf::RectangleShape player;
    void initPlayer(sf::Vector2f pos);
    
public:
    Player(sf::Vector2f pos);
    ~Player();
    Direction dir;
    void move();
    void render();
    void update();
    
};

#endif // PLAYER_H
