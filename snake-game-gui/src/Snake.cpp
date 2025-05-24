#include "Snake.h"

Snake::Snake(int startX, int startY) : body(1, {startX, startY}), direction(1) {}

void Snake::move() {
    auto head = body.front();
    switch (direction) {
        case 0: head.second--; break; // Up
        case 1: head.first++;  break; // Right
        case 2: head.second++; break; // Down
        case 3: head.first--;  break; // Left
    }
    body.insert(body.begin(), head);
    body.pop_back();
}

void Snake::grow() {
    body.push_back(body.back());
}

bool Snake::checkCollision() const {
    auto head = body.front();
    for (size_t i = 1; i < body.size(); ++i)
        if (body[i] == head)
            return true;
    return false;
}

void Snake::setDirection(int newDirection) {
    direction = newDirection;
}

std::pair<int, int> Snake::getHeadPosition() const {
    return body.front();
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}