#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Globals.h"
int user = 1;
int gameSpeed = 100;
int diff = 0;
int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");  
    Game game(40, 30); // 40x30 grid  
    
    while(window.isOpen() ){
        game.handleEvents(window);
        if(!game.get_gameOver()){
            game.update();
        }
        window.clear();
        if(user == 1){ // MENU SCREEN
            while(user != 0){
            while((user == 1) && window.isOpen()){
                window.clear();
                game.renderMenu(window);
                window.display();
            }
            if(user == 2){
                while((user == 2) && window.isOpen()){
                    window.clear();
                    game.renderDiff(window);
                    window.display();
                }
                if(diff == 0) {gameSpeed = 500;}
                else if(diff == 1) {gameSpeed = 300;}
                else if(diff == 2) {gameSpeed = 100;}
            }
            }
        }
        game.render(window);
        window.display();
        //sf::sleep(sf::milliseconds(5000));
        sf::sleep(sf::milliseconds(gameSpeed));
    }
    return 0;
}