#ifndef GAME_H
#define GAME_H
#include <LIBS.h>

#include <Window.h>
#include <Ball.h>
#include <Player.h>
class Game
{
private:
    Window window;
    Ball *ball;
    Player pl1;
    Player pl2;
    sf::Time timeStep = sf::seconds(1.f / 60.f);
public:
    Game();
    ~Game();
    void newGame();
    void checkCollision();
    void handleTnput();
    void update(sf::Time timeStep);
    void render();
    void runGame();
};

#endif // GAME_H
