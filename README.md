# Snake Game

## This is a version of the snake game

Error #1: So far I am trying to create the board for the snake game, however, whenever I run the program, I am not seeing the bottom half of the board.

Solution #1: okay so I found out that for some reason, the debugger terminal doesn't clear the terminal screen for whatever reason. Hence, if you are in VS code, you can run the program to compile it and then in your terminal, run `main.exe` and it should run fine. if you run into an infinte loop, use ctrl c.

Okay, I never realized how difficult it is to run C and C++ programs through VScode. I swear a few days ago, my `launch.json` and `tasks.json` files were configured properly, which allowed me to compile my files properly. But guess what, something happened and I wasn't able to compile my files. Luckily I fixed it.

Anyways, I added a file called `snakeGameV2.cpp` along with its corresponding `snakeGameV2.exe`. This is a version of the snake game done by geeksforgeeks. I am taking insperation from them.

Issue 1: I dont like how the screen flashes so much, using `system("cls")` is very easy and works, but it is very ugly and distracting. I think I learn more about the cinder library I can create a better game with a more user friendly envirenment.

Issue 2: Also, I dont like how GeeksforGeeks made the board so large, also, you move so much slower horizontaly than you do vertically. I want to find a way to keep the movement constant and also have the board be more of a sqaure.

Issue 2 (res): Okay so I thought about making the snake move faster when you are moving in the x direction because it would make the two directions match a little more but I couldn't really figure it out without making the whole game look strange and out of order. Hence, I moved on and I am starting to create the game using a GUI.

My hope with using a GUI will be that I can make the snake move with the same speed, x and y because I will have control over the amount of pixels it moves per second.

GUI IS WORKING!!! (not really :()
So I did a lot of research on what to use for a GUI when using C++ and by vast majority people said to use Qt. I tried getting it set up and I couldn't so I instead looked up basic GUI for C++ and I got the result to use SFML. After setting up classes and what not for food, the gameboard, and the snake, I finally got the SFML to work and a screen to pop up with a red dot. Problem is, the red dot does not work. I'll be back to report when it works.

Report: So I figured out what the heck was happening. I accidently multiplied the position of the snake, so it was going way off the board and hence I couldn't see it. I changed the initial position of the fruit and snake to (20,20), and (50, 50) respectively. 

Also, I added a sleep for 1 millisecond because the board was updating too fast, causing the snake to go HELLA fast, no bueno. So now I can see the snake, I can control the snake with wasd, I am for some reason having trouble using the arrow keys but I'll take a look at that later.

Problem: All this improvement is great but right now the snake is just going wherever it wants. It can go on any pixel, it can leave the board and it doesn't eat the fruit nor does it grow. I am going to task my self things to fix below:

Task 1: add proper boarder so that the snake cannot go off the board

Task 2: allow the snake to eat the fruit and grow when it does

Task 3: add columns to the board game that the snake and fuit follow. That way the game is more organised and it is clear when the board it full and all fruits have been eaten


