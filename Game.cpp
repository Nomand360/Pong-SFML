#include "Game.h"

Game::Game() : window(sf::Vector2u(800, 400), "Tenis SFML"), pl1(sf::Vector2f(0.f, 0.f)), pl2(sf::Vector2f(790.f, 0.f))
{
    srand(time(nullptr));
    this->newGame();
    this->runGame();
}

Game::~Game()
{

}

void Game::newGame()
{
    this->ball = new Ball();
}

void Game::checkCollision()
{
    if(this->pl1.getTopOfPaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(-static_cast<float>(rand() % 20 + 35));
    }else if(this->pl1.getBottomOfPaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(static_cast<float>(rand() % 20 + 35));
    }else if(this->pl1.getMidleOfOaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(static_cast<float>(rand()% 30 - 15));
    }

    if(this->pl2.getTopOfPaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(-static_cast<float>(rand() % 20 + 125));
    }else if(this->pl2.getBottomOfPaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(static_cast<float>(rand() % 20 + 125));
    }else if(this->pl2.getMidleOfOaddie().intersects(this->ball->getBounds())){
        this->ball->setDirection(static_cast<float>(rand()% 30 + 165));
    }
}

void Game::handleTnput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->pl1.setDirection(Direction::Up);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->pl1.setDirection(Direction::Down);
    }else{
        this->pl1.setDirection(Direction::None);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->pl2.setDirection(Direction::Up);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->pl2.setDirection(Direction::Down);
    }else{
        this->pl2.setDirection(Direction::None);
    }
}

void Game::update(sf::Time timeStep)
{
    this->ball->update(timeStep);
    this->ball->checkCollision(this->window.getWindowSize());

    this->handleTnput();
    this->pl1.update(timeStep, this->window.getWindowSize());
    this->pl2.update(timeStep, this->window.getWindowSize());
    this->checkCollision();

    if(this->ball->ballOut(this->window.getWindowSize())){
        this->ball->destroyBall();
        this->newGame();
    }

}

void Game::render()
{
    this->window.beginDraw();
    this->ball->render(*this->window.getRenderWindow());
    this->pl1.render(*this->window.getRenderWindow());
    this->pl2.render(*this->window.getRenderWindow());
    this->window.endDraw();
}

void Game::runGame()
{
    sf::Clock clock;
    sf::Time elapseTime = sf::Time::Zero;
    while(this->window.getRenderWindow()->isOpen()){
        this->window.update();
        elapseTime += clock.restart();
        while(elapseTime > this->timeStep){
            elapseTime -= this->timeStep;
            this->update(this->timeStep);
        }

        this->render();
    }
}
