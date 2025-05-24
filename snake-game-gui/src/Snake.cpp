#include "Snake.h"

Snake::Snake(int startX, int startY){
    body.clear();
    body.push_back({startX, startY});
    direction = 1;
}

void Snake::move(){
    auto head = body.front();
    switch (direction) {
        case 0: // Move up
        head.second--;
        break;
        case 1: // Move right
        head.first++;  
        break; 
        case 2: // Move down
        head.second++;
        break;
        case 3: // Move left
        head.first--;
        break;
    }
    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::grow(){
    body.push_back(body.back());
}

bool Snake::checkCollision() const{
    auto head = body.front();
    for (size_t i = 1; i < body.size(); ++i)
        if (body[i] == head)
            return true;
    return false;
}

void Snake::setDirection(int newDirection){
    direction = newDirection;
}

std::pair<int, int> Snake::getHeadPosition() const{
    return body.front();
}

const std::vector<std::pair<int, int>>& Snake::getBody() const{
    return body;
}