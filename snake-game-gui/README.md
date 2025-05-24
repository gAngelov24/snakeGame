# Snake Game GUI

This project is an upgraded version of the classic Snake game, implemented with a GUI. The game allows players to control a snake that grows in length as it consumes food, while avoiding collisions with the walls and itself.

## Project Structure

The project is organized as follows:

```
snake-game-gui
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── Game.cpp          # Implementation of the Game class
│   ├── Game.h            # Declaration of the Game class
│   ├── Snake.cpp         # Implementation of the Snake class
│   ├── Snake.h           # Declaration of the Snake class
│   ├── Food.cpp          # Implementation of the Food class
│   ├── Food.h            # Declaration of the Food class
│   └── gui
│       ├── Window.cpp     # Implementation of the Window class
│       └── Window.h       # Declaration of the Window class
├── CMakeLists.txt        # CMake configuration file
└── README.md              # Project documentation
```

## Setup Instructions

- Use the arrow keys or WASD to control the snake's movement.
- The objective is to eat the food (represented by a specific icon) to grow the snake.
- Avoid colliding with the walls or the snake's own body.
- The game ends when a collision occurs.

Enjoy playing the Snake game with a new graphical interface!(If you want to suffer, play the old one that runs in the console ;))