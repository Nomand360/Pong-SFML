#ifndef WINDOW_H
#define WINDOW_H
#include <LIBS.h>

class Window
{
private:
    sf::RenderWindow window;
    sf::Vector2u window_size;
    std::string window_title;
    void setupWindow(const sf::Vector2u &size, const std::string title);
    void create();
    void destroy();
public:
    Window();
    Window(const sf::Vector2u &size, const std::string title);
    ~Window();
    void beginDraw();
    void endDraw();
    void update();
    sf::Vector2u getWindowSize();
    sf::RenderWindow *getRenderWindow();
    void draw(sf::Drawable &drawable);
};

#endif // WINDOW_H
