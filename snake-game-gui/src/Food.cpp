#include "Food.h"
#include <cstdlib>

Food::Food(){
    x = 15;
    y = 10;
    width = 40;
    height = 30;
}

Food::Food(int width, int height) : width(width), height(height){
    spawn();
}

void Food::spawn(){
    x = rand() % width;
    y = rand() % height;
}

std::pair<int, int> Food::getPosition() const{
    return {x, y};
}