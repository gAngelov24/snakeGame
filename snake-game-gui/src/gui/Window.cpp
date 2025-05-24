#include "Window.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Window::Window(int width, int height, const std::string& title) 
    : window(sf::VideoMode(width, height), title) {}

void Window::create() {
    window.setFramerateLimit(60);
}

void Window::display() {
    window.display();
}

void Window::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

bool Window::isOpen() const {
    return window.isOpen();
}