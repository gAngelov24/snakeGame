#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window{
public:
    Window(int width, int height, const std::string& title);
    void create();
    void display();
    void handleEvents();
    bool isOpen() const;

private:
    sf::RenderWindow window;
};

#endif // WINDOW_H