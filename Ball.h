#ifndef BALL_H
#define BALL_H
#include <LIBS.h>
#include <math.h>

class Ball
{
private:
    const float PI = 3.1415926f;
    sf::CircleShape *ball;
    float speed_ball;
    float ball_angle;
    sf::Vector2f direction_ball;
    void createBall();
public:
    Ball();
    ~Ball();
    sf::FloatRect getBounds();
    bool ballOut(sf::Vector2u size);
    void setDirection(float angle);
    void render(sf::RenderWindow &window);
    void destroyBall();
    void update(sf::Time deltaTime);
    void checkCollision(sf::Vector2u size);
};

#endif // BALL_H
