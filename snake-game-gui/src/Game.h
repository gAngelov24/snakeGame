#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

class Game{
public:
    Game(int width, int height);
    void handleEvents(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    bool get_gameOver();

private:
    Snake snake;
    Food food;
    int score;
    bool gameOver;
    int width, height;
};

#endif // GAME_H