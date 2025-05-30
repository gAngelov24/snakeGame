#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>

class Snake{
public:
    Snake(int startX, int startY);
    Snake(int startX, int startY, int dir);
    void move();
    void grow();
    void reset();
    bool checkCollision() const;
    void setDirection(int newDirection);
    int getDirection();
    std::pair<int, int> getHeadPosition() const;
    const std::vector<std::pair<int, int>>& getBody() const;

private:
    std::vector<std::pair<int, int>> body;
    int direction; // 0: up, 1: right, 2: down, 3: left
};

#endif // SNAKE_H