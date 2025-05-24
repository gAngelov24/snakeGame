#include "Game.h"
#include <SFML/Window/Event.hpp>

Game::Game(int width, int height)
    : snake(width / 2, height / 2), food(width, height), score(0), gameOver(false), width(width), height(height) {}

void Game::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)    snake.setDirection(0);
            if (event.key.code == sf::Keyboard::Right) snake.setDirection(1);
            if (event.key.code == sf::Keyboard::Down)  snake.setDirection(2);
            if (event.key.code == sf::Keyboard::Left)  snake.setDirection(3);
        }
    }
}

void Game::update() {
    snake.move();
    if (snake.getHeadPosition() == food.getPosition()) {
        snake.grow();
        food.spawn();
        score += 10;
    }
    // TODO: Add collision with self and walls
}

void Game::render(sf::RenderWindow& window) {
    // Draw snake
    for (const auto& segment : snake.getBody()) {
        sf::RectangleShape rect(sf::Vector2f(20, 20));
        rect.setPosition(segment.first * 20, segment.second * 20);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }
    // Draw food
    sf::CircleShape foodShape(10);
    foodShape.setFillColor(sf::Color::Red);
    foodShape.setPosition(food.getPosition().first * 20, food.getPosition().second * 20);
    window.draw(foodShape);
}