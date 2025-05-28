#ifndef FOOD_H
#define FOOD_H

#include <utility>

class Food {
public:
    Food();
    Food(int width, int height);
    void reset();
    void spawn();
    std::pair<int, int> getPosition() const;

private:
    int x, y;
    int width, height;
};

#endif // FOOD_H