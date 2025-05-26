#include "Snake.h"

Snake::Snake(int startX, int startY){
    body.clear();
    body.push_back({startX, startY});
    direction = 1;
}

Snake::Snake(int startX, int startY, int dir){
    body.clear();
    body.push_back({startX, startY});
    direction = dir;
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
    std::pair<int,int> head = body.front();
    if(body.size() == 1){
        if(direction == 0){
            body.push_back({head.first, head.second++});
        } else if(direction == 1){
            body.push_back({head.first--, head.second});
        } else if(direction == 2){
            body.push_back({head.first, head.second--});
        } else {
            body.push_back({head.first++, head.second});
        }
    } else{
        body.push_back(body.back());
    }
}

bool Snake::checkCollision() const{
    std::pair<int,int> head = body.front();
    for (int i = 1; i < body.size(); i++){
        if (body[i] == head){
            return true;
        }
    }
    return false;
}

void Snake::setDirection(int newDirection){
    direction = newDirection;
}

int Snake::getDirection(){
    return direction;
}

std::pair<int, int> Snake::getHeadPosition() const{
    return body.front();
}

const std::vector<std::pair<int, int>>& Snake::getBody() const{
    return body;
}