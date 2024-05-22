#include <iostream>

#include "./lib/ball/Ball.h"
#include "./lib/wall/Wall.h"
#include "./lib/vector/Vector.h"
#include <SFML/Graphics.hpp>

#define SCREEN_HEIGHT 500
#define SCREEN_WIDTH 1000

int main(){

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Circle Demo");

    // Create a circle shape
    Ball b1(Vector(50,100,0),10);
    b1.setAcceleration(Vector(0,-9.8,0));

    Wall floor(Vector(0,20,0),SCREEN_WIDTH,20);



    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        //draw floor
        floor.render(window,SCREEN_HEIGHT);

        // Draw the circle
        b1.update(0.016f);
        if(b1.checkCollision(floor)){
            Vector oldVel(b1.getVelocity());
            oldVel.setY(oldVel.getY()*-1);
            b1.setVelocity(oldVel);
        }
        b1.render(window,SCREEN_HEIGHT);

        // Update the window
        window.display();
    }

    return 0;

}