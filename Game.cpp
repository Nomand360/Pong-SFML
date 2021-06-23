#include "Game.h"

Game::Game() : window(sf::Vector2u(800, 400), "Tenis SFML")
{
    srand(time(nullptr));

    this->runGame();
}

Game::~Game()
{

}

void Game::handleTnput()
{

}

void Game::update()
{
    this->window.update();
    this->ball.checkCollision(this->window.getWindowSize());

    this->elapseTime += this->clock.restart();
    while(this->elapseTime >= timeStep){
        this->elapseTime -= timeStep;

        this->ball.update(timeStep);

    }



}

void Game::render()
{
    this->window.beginDraw();
    this->ball.render(*this->window.getRenderWindow());
    this->window.endDraw();
}

sf::Time Game::getElapsed()
{
    return this->elapseTime;
}

void Game::restartClock()
{

}

void Game::runGame()
{
    while(this->window.getRenderWindow()->isOpen()){
        this->update();
        this->render();
    }
}
