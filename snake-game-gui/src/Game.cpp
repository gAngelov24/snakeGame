#include "Game.h"
#include "Globals.h"
#include <SFML/Window/Event.hpp>

// game ctor
Game::Game(int width, int height) : snake(10, 10), food(), score(0), gameOver(false), width(width), height(height) {}

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
        } else if(gameOver){
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            sf::Font font;
            if (!font.loadFromFile("Fonts\\Roboto-Black.ttf")) return;
            sf::Text playAgainText;
            playAgainText.setFont(font);
            playAgainText.setString("Play Again?");
            playAgainText.setCharacterSize(30);
            sf::FloatRect playAgainBounds = playAgainText.getLocalBounds();
            playAgainText.setOrigin(playAgainBounds.left + playAgainBounds.width / 2.0f, playAgainBounds.top + playAgainBounds.height / 2.0f);
            playAgainText.setPosition(window.getSize().x / 2.0f, (window.getSize().y * (2.0f/3.0f)));
            sf::FloatRect globalBounds = playAgainText.getGlobalBounds();
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                if (globalBounds.contains((float)mouse.x, (float)mouse.y)) {
                   reset();
                    user = 1;
                }
            }
        }
    }
}

void Game::update(){
    snake.move();

    if(snake.getHeadPosition().first < 0 || snake.getHeadPosition().first >= width || snake.getHeadPosition().second < 0 || snake.getHeadPosition().second >= height || snake.checkCollision()){
        gameOver = true;
    } else if(snake.getHeadPosition() == food.getPosition()){
        snake.grow();
        food.spawn();
        score += 10;
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
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
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
        if (!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        sf::Text text2;
        text2.setFont(font);
        text2.setString("Game Over!"); 
        text2.setCharacterSize(40); 
        text2.setFillColor(sf::Color::Red); 
        sf::FloatRect textRect = text2.getLocalBounds();
        text2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text2.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f);

        window.draw(text2);

        sf::Text text3;
        text3.setFont(font);
        std::string final_str = "Final Score: " + std::to_string(score);
        text3.setString(final_str);
        text3.setCharacterSize(30);
        text3.setFillColor(sf::Color::White);
        sf::FloatRect rect = text3.getLocalBounds();
        text3.setOrigin(rect.left + rect.width / 2.0f , rect.top + rect.height / 2.0f);
        text3.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 2.0f));

        window.draw(text3);

        sf::Text text4; // init text obj
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
        text4.setFont(font);
        text4.setString("Play Again?"); // set the string
        text4.setCharacterSize(30); // set the text size
        sf::FloatRect playAgainButton = text4.getLocalBounds(); // init textbox
        // define the origin of the textbox, and set its postion
        text4.setOrigin(playAgainButton.left + playAgainButton.width / 2.0f, playAgainButton.top + playAgainButton.height / 2.0f);
        text4.setPosition(window.getSize().x / 2.0f, (window.getSize().y * (2.0f/3.0f)));

        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        sf::FloatRect bounds = text4.getGlobalBounds();
        if(bounds.contains((float)mouse.x , (float)mouse.y)){
            if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
                return;
            }
            text4.setFillColor(sf::Color::Blue); 
        } else{
            if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
                return;
            } 
            text4.setFillColor(sf::Color::Red); 
        }
        text4.setFont(font);
        window.draw(text4);

    }
}

void Game::renderMenu(sf::RenderWindow& window){
    /**** TITLE *****/
    sf::Font font; // init Font obj
    sf::Text text; // init text obj
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text.setFont(font);
    text.setString("--Snake Game by George Angelov--"); // set the string
    text.setCharacterSize(40); // set the text size
    sf::FloatRect textRect = text.getLocalBounds(); // init textbox
    // define the origin of the textbox, and set its postion
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f);

    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    sf::FloatRect bounds = text.getGlobalBounds();
    if(bounds.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        }
        text.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text.setFillColor(sf::Color::Blue); 
    }
    text.setFont(font);
    window.draw(text);

    /**** SELECT DIFF BUTTON *****/
    sf::Text text2;
    text2.setString("Select Difficulty");
    text2.setCharacterSize(30);
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text2.setFont(font);
    sf::FloatRect menuBox = text2.getLocalBounds();
    text2.setOrigin(menuBox.left + menuBox.width / 2.0f , menuBox.top + menuBox.height / 2.0f);
    text2.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 2.0f));

    sf::FloatRect bounds2 = text2.getGlobalBounds();
    if(bounds2.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Bold.ttf")){
            return;
        }// snake-game-gui\Fonts
        text2.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text2.setFillColor(sf::Color::White); 
    }
    text2.setFont(font);
    window.draw(text2);

    /**** PLAY BUTTON *****/
    sf::Text text3;
    text3.setString("Play!");
    text3.setCharacterSize(30);
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text3.setFont(font);
    sf::FloatRect PlayButton = text3.getLocalBounds();
    text3.setOrigin(PlayButton.left + PlayButton.width / 2.0f , PlayButton.top + PlayButton.height / 2.0f);
    text3.setPosition(window.getSize().x / 2.0f , (window.getSize().y * (2.0f/3.0f)));

    sf::FloatRect bounds3 = text3.getGlobalBounds();
    if(bounds3.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Bold.ttf")){
            return;
        }
        text3.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text3.setFillColor(sf::Color::White); 
    }
    text3.setFont(font);
    window.draw(text3);

    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
            user = 0;
        } else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                if(bounds2.contains((float)mouse.x, (float)mouse.y)){
                    user = 2; // Select Difficulty
                } else if(bounds3.contains((float)mouse.x, (float)mouse.y)){
                    user = 0; // Play!
                }
            }
        }
    }
}

void Game::renderDiff(sf::RenderWindow& window){
    /**** TITLE *****/
    sf::Font font; // init Font obj
    sf::Text text; // init text obj
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text.setFont(font);
    text.setString("--Select Difficulty--"); // set the string
    text.setCharacterSize(40); // set the text size
    sf::FloatRect textRect = text.getLocalBounds(); // init textbox
    // define the origin of the textbox, and set its postion
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f);

    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    sf::FloatRect bounds = text.getGlobalBounds();
    if(bounds.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        }
        text.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text.setFillColor(sf::Color::Blue); 
    }
    text.setFont(font);
    window.draw(text);

    /**** EASY DIFF BUTTON *****/
    sf::Text text2;
    text2.setString("Easy");
    text2.setCharacterSize(30);
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text2.setFont(font);
    sf::FloatRect easyButton = text2.getLocalBounds();
    text2.setOrigin(easyButton.left + easyButton.width / 2.0f , easyButton.top + easyButton.height / 2.0f);
    text2.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 3.0f) + textRect.height);

    sf::FloatRect bounds2 = text2.getGlobalBounds();
    if(bounds2.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Bold.ttf")){
            return;
        }// snake-game-gui\Fonts
        text2.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text2.setFillColor(sf::Color::White); 
    }
    text2.setFont(font);
    window.draw(text2);

    /**** MEDIUM DIFF BUTTON *****/
    sf::Text text3;
    text3.setString("Medium");
    text3.setCharacterSize(30);
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text3.setFont(font);
    sf::FloatRect mediumButton = text3.getLocalBounds();
    text3.setOrigin(mediumButton.left + mediumButton.width / 2.0f , mediumButton.top + mediumButton.height / 2.0f);
    text3.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 3.0f) + 2*textRect.height);

    sf::FloatRect bounds3 = text3.getGlobalBounds();
    if(bounds3.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Bold.ttf")){
            return;
        }
        text3.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text3.setFillColor(sf::Color::White); 
    }
    text3.setFont(font);
    window.draw(text3);

    /**** HARD DIFF BUTTON *****/
    sf::Text text4;
    text4.setString("Hard");
    text4.setCharacterSize(30);
    if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){return;}
    text4.setFont(font);
    sf::FloatRect hardButton = text4.getLocalBounds();
    text4.setOrigin(hardButton.left + hardButton.width / 2.0f , hardButton.top + hardButton.height / 2.0f);
    text4.setPosition(window.getSize().x / 2.0f , (window.getSize().y / 3.0f) + 3*textRect.height);

    sf::FloatRect bounds4 = text4.getGlobalBounds();
    if(bounds4.contains((float)mouse.x , (float)mouse.y)){
        if(!font.loadFromFile("Fonts\\Roboto-Bold.ttf")){
            return;
        }
        text4.setFillColor(sf::Color::Red); 
    } else{
        if(!font.loadFromFile("Fonts\\Roboto-Black.ttf")){
            return;
        } 
        text4.setFillColor(sf::Color::White); 
    }
    text4.setFont(font);
    window.draw(text4);

    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
            user = 0;
        } else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mouse = sf::Mouse::getPosition(window);
                if(bounds2.contains((float)mouse.x, (float)mouse.y)){
                    diff = 0; // easy diff was selected
                    user = 1;
                } else if(bounds3.contains((float)mouse.x, (float)mouse.y)){
                    diff = 1; // medium diff was selected
                    user = 1;
                } else if(bounds4.contains((float)mouse.x, (float)mouse.y)){
                    diff = 2; // hard diff was selected
                    user = 1;
                }
            }
        }
    }
}

void Game::checkCollision(){
    if(snake.checkCollision()){
        gameOver = true;
    }
}

void Game::reset(){
    food.reset();
    snake.reset();
    score = 0;
    gameOver = false;
}