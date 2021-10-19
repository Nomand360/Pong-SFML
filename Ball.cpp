#include "Ball.h"

void Ball::createBall()
{
    this->ball_angle = 180.f * (PI / 180);
    this->speed_ball = 250.f;
    this->direction_ball = sf::Vector2f(std::cos(this->ball_angle), std::sin(this->ball_angle));
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

sf::FloatRect Ball::getBounds()
{
    return this->ball->getGlobalBounds();
}

bool Ball::ballOut(sf::Vector2u size)
{
    if((this->ball->getPosition().x + this->ball->getRadius() * 2 > size.x && (this->direction_ball.x > 0)) ||
                (this->ball->getPosition().x < 0 && (this->direction_ball.x < 0))){
        return true;
        }else{
        return false;
    }
}

void Ball::setDirection(float angle)
{
    this->direction_ball.x = std::cos(angle * (PI /180));
    this->direction_ball.y = std::sin(angle * (PI /180));
    this->speed_ball += 5.f;
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
    /**/
    if((this->ball->getPosition().y + this->ball->getRadius() * 2 > size.y && (this->direction_ball.y > 0)) ||
            (this->ball->getPosition().y < 0 && (this->direction_ball.y < 0))){
        this->direction_ball.y = -this->direction_ball.y;
    }
}
