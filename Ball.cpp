#include "Ball.h"

void Ball::createBall()
{
    this->speed_ball = 100.f;
    this->direction_ball = sf::Vector2f(3.f, 1.7f);
    this->ball = new sf::CircleShape();
    this->ball->setRadius(5.f);
    this->ball->setFillColor(sf::Color::White);
    this->ball->setPosition(400.f + this->ball->getRadius(), 200.f + this->ball->getRadius());

}

Ball::Ball()
{
    this->createBall();

}

Ball::~Ball()
{
    this->destroyBall();
}

void Ball::render(sf::RenderWindow &window)
{
    window.draw(*this->ball);
}

void Ball::destroyBall()
{
    delete this->ball;
}

void Ball::update(sf::Time deltaTime)
{
    this->ball->move(this->direction_ball * (this->speed_ball * deltaTime.asSeconds()));
}

void Ball::checkCollision(sf::Vector2u size)
{
    if((this->ball->getPosition().x + this->ball->getRadius() * 2 > size.x && (this->direction_ball.x > 0)) ||
            (this->ball->getPosition().x < 0 && (this->direction_ball.x < 0))){
        this->direction_ball.x = -this->direction_ball.x;
    }
    if((this->ball->getPosition().y + this->ball->getRadius() * 2 > size.y && (this->direction_ball.y > 0)) ||
            (this->ball->getPosition().y < 0 && (this->direction_ball.y < 0))){
        this->direction_ball.y = -this->direction_ball.y;
    }
}
