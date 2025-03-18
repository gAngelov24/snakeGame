#include <iostream>
#include <stdlib.h>
#include <conio.h>
#define clrscr(); system("cls");
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
 
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{   
    //system("CLS");
    clrscr();
    for(int i = 0; i < width+2; i++){
        std::cout << "#";
    } 
    std::cout << endl;

    for(int i = 0; i < height; i++){
       for(int j = 0; j < width; j++){
            if(j == 0){
                std::cout << "# ";
            } else {
                std::cout << " ";
            }
            

            if(j == width - 1){
                std::cout << "#";
            }
        }
        std::cout << endl;
    }

    for(int i = 0; i < width+2; i++){
        std::cout << "#";
    }
    std::cout << endl;
    
}
void Input()
{

}
void Logic()
{

}
int main()
{
    Setup();
    
    while(!gameOver){
        Draw();
        //gameOver = true;
        Input();
        Logic();
        //Sleep(10)
    }

    return 0;
}