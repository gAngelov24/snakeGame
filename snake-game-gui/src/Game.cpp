#include "Game.h"
#include <SFML/Window/Event.hpp>

// game ctor
Game::Game(int width, int height) : snake(10, 10), food(width, height), score(0), gameOver(false), width(width), height(height) {}

// get gameOver
bool Game::get_gameOver(){
    return gameOver;
}

void Game::handleEvents(sf::RenderWindow& window){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        } else if(event.type == sf::Event::KeyPressed){
            if((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) && (snake.getDirection() != 2)){
                snake.setDirection(0);
            }
            if((event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) && (snake.getDirection() != 3)){
                snake.setDirection(1);
            }
            if((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) && (snake.getDirection() != 0)){
                snake.setDirection(2);
            }
            if((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) && (snake.getDirection() != 1)){
                snake.setDirection(3);
            }
        }
    }
}

void Game::update(){
    snake.move();
    if(snake.getHeadPosition() == food.getPosition()){
        snake.grow();
        food.spawn();
        score += 10;
    }
    
    if(snake.getHeadPosition().first < 0 || snake.getHeadPosition().first >= width || snake.getHeadPosition().second < 0 || snake.getHeadPosition().second >= height){
        gameOver = true;
    }
    
}

void Game::render(sf::RenderWindow& window){
    // Draw snake
    for (std::vector<std::pair<int, int>>::const_iterator it = snake.getBody().begin(); it != snake.getBody().end(); it++){
        const std::pair<int, int>& segment = *it;
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

    // Update Score
    if(!gameOver){
        sf::Font font;
        if(!font.loadFromFile("C:\\Users\\George Angelov\\Documents\\VS_Code_Projects\\Fonts\\Roboto-Black.ttf")){
            return;
        }
        sf::Text text;
        text.setFont(font);
        std::string score_str = "Score: " + std::to_string(score);
        text.setString(score_str);
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);
        sf::FloatRect text_rec = text.getLocalBounds();
        text.setOrigin(text_rec.left + text_rec.width , text_rec.top + text_rec.height);
        text.setPosition(window.getSize().x , window.getSize().y);
        window.draw(text);
    } else if(gameOver){
        sf::Font font;
        if (!font.loadFromFile("C:\\Users\\George Angelov\\Documents\\VS_Code_Projects\\Fonts\\Roboto-Black.ttf")){
            return;
        } //"C:\Users\George Angelov\Documents\VS_Code_Projects\Fonts\Roboto-Black.ttf"
        sf::Text text2;
        text2.setFont(font);
        text2.setString("Game Over!"); 
        text2.setCharacterSize(40); 
        text2.setFillColor(sf::Color::Red); 
        sf::FloatRect textRect = text2.getLocalBounds();
        text2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text2.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

        window.draw(text2);

        sf::Text text3;
        text3.setFont(font);
        std::string final_str = "Final Score: " + std::to_string(score);
        text3.setString(final_str);
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::White);
        sf::FloatRect rect = text3.getLocalBounds();
        text3.setOrigin(rect.left + rect.width / 2.0f , rect.top + rect.height / 2.0f);
        text3.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 2.0f) + (textRect.height));

        window.draw(text3);
    }
}

void Game::checkCollision(){
    if(snake.checkCollision()){
        gameOver = true;
    }
}