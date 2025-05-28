#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

class Game{
public:
    Game(int width, int height);
    void handleEvents(sf::RenderWindow& window); // x is ready bit to tell if game has started
    void update();
    void reset();
    void render(sf::RenderWindow& window);
    void renderMenu(sf::RenderWindow& window);
    void renderDiff(sf::RenderWindow& window);
    bool get_gameOver();
    void checkCollision();

private:
    Snake snake;
    Food food;
    int score;
    bool gameOver;
    int width, height;
};

#endif // GAME_H