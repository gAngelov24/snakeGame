#include "Game.h"
#include <SFML/Window/Event.hpp>

Game::Game(int width, int height) : snake(width / 2, height / 2), food(width, height), score(0), gameOver(false), width(width), height(height) {}

void Game::handleEvents(sf::RenderWindow& window){
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W){
                snake.setDirection(0);
            }
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D){
                snake.setDirection(1);
            }
            if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S){
                snake.setDirection(2);
            }
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A){
                snake.setDirection(3);
            }
        }
    }
}

void Game::update(){
    snake.move();
    if (snake.getHeadPosition() == food.getPosition()) {
        snake.grow();
        food.spawn();
        score += 10;
    }
    // TODO: Add collision with self and walls
}

void Game::render(sf::RenderWindow& window){
    // Draw snake
    for (std::vector<std::pair<int, int>>::const_iterator it = snake.getBody().begin(); it != snake.getBody().end(); it++){
        const std::pair<int, int>& segment = *it;
        sf::RectangleShape rect(sf::Vector2f(20, 20));
        rect.setPosition(segment.first + 50, segment.second + 50);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }
    // Draw food
    sf::CircleShape foodShape(10);
    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition(food.getPosition().first + 20, food.getPosition().second + 20);
    window.draw(foodShape);
}