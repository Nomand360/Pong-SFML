#ifndef GAME_H
#define GAME_H
#include <LIBS.h>

#include <Window.h>
#include <Ball.h>
class Game
{
private:
    Window window;
    Ball ball;
    sf::Clock clock;
    sf::Time timeStep = sf::seconds(1.f / 60.f);
    sf::Time elapseTime = sf::Time::Zero;
public:
    Game();
    ~Game();
    void handleTnput();
    void update();
    void render();
    sf::Time getElapsed();
    void restartClock();
    void runGame();
};

#endif // GAME_H
