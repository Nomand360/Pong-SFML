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
    const sf::FloatRect getTopOfPaddie();
    const sf::FloatRect getMidleOfOaddie();
    const sf::FloatRect getBottomOfPaddie();
    void checkCollision(sf::Vector2u size);
    void setDirection(Direction d);
    void move(sf::Time delta);
    void render(sf::RenderWindow &window);
    void update(sf::Time deltaTime, sf::Vector2u size);
};

#endif // PLAYER_H
