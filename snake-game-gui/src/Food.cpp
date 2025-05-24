#include "Food.h"
#include <cstdlib>

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