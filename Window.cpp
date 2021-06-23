#include "Window.h"

void Window::setupWindow(const sf::Vector2u &size, const std::string title)
{
    this->window_size = size;
    this->window_title = title;
    this->create();
}

void Window::create()
{
    this->window.create({this->window_size.x, this->window_size.y}, this->window_title, sf::Style::Default);
    this->window.setVerticalSyncEnabled(true);
}

void Window::destroy()
{
    this->window.close();
}

Window::Window()
{
    this->setupWindow(sf::Vector2u(640, 480), "SFML");
}

Window::Window(const sf::Vector2u &size, const std::string title)
{
    this->setupWindow(size, title);
}

Window::~Window()
{
    this->destroy();
}

void Window::beginDraw()
{
    this->window.clear();
}

void Window::endDraw()
{
    this->window.display();
}

void Window::update()
{
    sf::Event event;
    while(this->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->destroy();
        }
    }
}

sf::Vector2u Window::getWindowSize()
{
    return this->window.getSize();
}

sf::RenderWindow *Window::getRenderWindow()
{
    return &this->window;
}

void Window::draw(sf::Drawable &drawable)
{
    this->window.draw(drawable);
}
