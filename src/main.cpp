#include <iostream>
#include <vector>

#include "./lib/ball/Ball.h"
#include "./lib/wall/Wall.h"
#include "./lib/vector/Vector.h"
#include <SFML/Graphics.hpp>

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 1000
#define DELTA_T 0.007
#define GRAVITY 9.8f

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Circle Demo");

    // Create a circle shape


    //create walls
    std::vector<Wall> walls;
    std::vector<Ball> balls;

    balls.emplace_back(Vector(200,300,0),Vector(0,40,0),10);
    balls.emplace_back(Vector(200,350,0),Vector(0,-100,0),20);
    //balls.emplace_back(Vector(40,40,0),Vector(0,56,0),12);

    walls.emplace_back(Vector(0, 0, 0), SCREEN_WIDTH, 10); // Floor
    walls.emplace_back(Vector(0, SCREEN_HEIGHT - 10, 0), SCREEN_WIDTH, 10); // Ceiling
    walls.emplace_back(Vector(0, 0, 0), 10, SCREEN_HEIGHT); // Left wall
    walls.emplace_back(Vector(SCREEN_WIDTH - 10, 0, 0), 10, SCREEN_HEIGHT); // Right wall
    for (Wall& wall : walls) {
        wall.setCOR(0.745);
    }


    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //Mouse Click
            if (event.type == sf::Event::MouseButtonPressed){

            }
        }

        // Clear screen
        window.clear();

        // Handle collisions between balls and walls
        for (size_t i = 0; i < balls.size(); ++i) {
            
            //check for collision with wall
            for (Wall& wall : walls) {
                if (balls[i].checkCollision(wall)) {
                    balls[i].handleCollision(wall);
                }
            }

            //check for collision with other balls
            for (size_t j = i + 1; j < balls.size(); ++j) {
                if (balls[i].checkCollision(balls[j])) {
                    balls[i].handleCollision(balls[j]);
                }
            }
        }

        //Drawing 
        for (Wall& wall : walls) {
            wall.render(window, SCREEN_HEIGHT);
        }
        for (Ball& ball : balls) {
            // Draw the circle
            ball.updateWithDrag(GRAVITY,1.293f,DELTA_T);
            ball.move(DELTA_T);

            ball.render(window,SCREEN_HEIGHT);
        }
        // Update the window
        window.display();
    }

    return 0;

}