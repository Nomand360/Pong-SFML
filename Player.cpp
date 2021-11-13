#include "Player.h"
#include <iostream>

void Player::initPlayer(sf::Vector2f pos)
{
    this->speed = 400.f;
    sf::Vector2f size(10.f, 75.f);
    this->player.setSize(size);
    this->player.setFillColor(sf::Color::White);
    this->player.setPosition(pos);
}

Player::Player(sf::Vector2f pos)
{
   this->initPlayer(pos);
}

Player::~Player()
{

}

const sf::FloatRect Player::getTopOfPaddie()
{
    return sf::FloatRect(this->player.getPosition().x, this->player.getPosition().y, this->player.getGlobalBounds().width, 15.f);
}

const sf::FloatRect Player::getMidleOfOaddie()
{
    return sf::FloatRect(this->player.getPosition().x, this->player.getPosition().y + 15.f, this->player.getGlobalBounds().width, 45.f);
}

const sf::FloatRect Player::getBottomOfPaddie()
{
    return sf::FloatRect(this->player.getPosition().x, this->player.getPosition().y + 60.f, this->player.getGlobalBounds().width, 15.f);
}

void Player::checkCollision(sf::Vector2u size)
{
    if(this->player.getPosition().y <= 0.f && (this->dir != Direction::Down)){
        this->setDirection(Direction::None);
    }
    if(this->player.getPosition().y + this->player.getSize().y >= size.y && (this->dir != Direction::Up)){
        this->setDirection(Direction::None);
    }
}

void Player::setDirection(Direction d)
{
    this->dir = d;
}

void Player::move(sf::Time delta)
{
    switch (this->dir) {
    case Direction::Up:{
        this->player.move(0, -1.f * (speed * delta.asSeconds()));
        break;
    }
    case Direction::Down:{
        this->player.move(0, 1.f * (speed * delta.asSeconds()));
        break;
    }
    case Direction::None:{
        this->player.move(0, 0);
        break;
    }
    }
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(this->player);
}

void Player::update(sf::Time deltaTime, sf::Vector2u size)
{
    this->checkCollision(size);
    this->move(deltaTime);
}
