#include <SFML/Graphics.hpp>
#include "Game.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    Game game(40, 30); // 40x30 grid


    while (window.isOpen()){
        game.handleEvents(window);
        if(!game.get_gameOver()){
            game.update();
        }
        window.clear();
        game.render(window);
        window.display();
        sf::sleep(sf::milliseconds(50));
    }
    return 0;
}