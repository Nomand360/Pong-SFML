#ifndef BALL_H
#define BALL_H
#include <LIBS.h>

class Ball
{
private:
    sf::CircleShape *ball;
    float speed_ball;
    sf::Vector2f direction_ball;
    void createBall();
public:
    Ball();
    ~Ball();
    void render(sf::RenderWindow &window);
    void destroyBall();
    void update(sf::Time deltaTime);
    void checkCollision(sf::Vector2u size);
};

#endif // BALL_H
