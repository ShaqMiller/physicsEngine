#include "Ball.h"
#include "../wall/Wall.h"

#include <cmath>
#include <iostream>
// Default constructor
Ball::Ball() : Object(), radius(1.0f) {
    // Initialize the circle shape
    shape.setRadius(1.0f);
    shape.setFillColor(sf::Color::White);
    mass=(4/3) * M_PI * radius * radius*radius * 1100 ;
}

// Constructor with position and radius
Ball::Ball(double x, double y, double z, double r) : Object(x, y, z), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    mass=(4/3) * M_PI * radius * radius*radius * 1100 ;
}

// Constructor with position, velocity, and radius
Ball::Ball(double x, double y, double z, Vector v, double r) : Object(x, y, z, v), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    mass=(4/3) * M_PI * radius * radius*radius * 1100 ;
}

// Constructor with position vector and radius
Ball::Ball(Vector pos, double r) : Object(pos), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    mass=(4/3) * M_PI * radius * radius*radius * 1100 ;
}

// Constructor with position vector, velocity vector, and radius
Ball::Ball(Vector pos, Vector v, double r) : Object(pos, v), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    mass=(4/3) * M_PI * radius * radius*radius * 1100 ;
}

// Destructor
Ball::~Ball() {}

// Getter for radius
double Ball::getRadius() const {
    return radius;
}

// Setter for radius
void Ball::setRadius(double r) {
    radius = r;
}

void Ball::render(sf::RenderWindow& window, float window_height) {
    float inverted_y = window_height - getPos().getY();
    shape.setPosition(getPos().getX(), inverted_y);
    
    window.draw(shape);
}


bool Ball::checkCollision(const Wall& wall) const {
    // Check if the ball has collided with the wall
    float ballLeft = pos.getX();
    float ballRight = pos.getX() + radius*2;
    float ballBottom = pos.getY() -radius*2;
    float ballTop = pos.getY();

    float wallLeft = wall.getPos().getX();
    float wallRight = wallLeft + wall.getWidth();
    float wallBottom = wall.getPos().getY();
    float wallTop = wall.getPos().getY() + wall.getHeight();

    bool overlapX = (ballLeft<wallRight &&ballRight>wallRight) || (ballRight>wallLeft &&ballLeft<wallLeft);;
    bool overlapY = (ballBottom<wallTop &&ballTop>wallTop)     || (ballTop>wallBottom &&ballBottom<wallBottom);


    return overlapX || overlapY;
}

Vector Ball::getPenetrationVector(const Wall& wall) const {
    Vector penetration(0, 0, 0);

    // Calculate the penetration depth along the x and y axis
    float ballLeft = pos.getX();
    float ballRight = pos.getX() + radius*2;
    float ballBottom = pos.getY() -radius*2;
    float ballTop = pos.getY();

    float wallLeft = wall.getPos().getX();
    float wallRight = wall.getPos().getX() + wall.getWidth();
    float wallBottom = wall.getPos().getY();
    float wallTop = wall.getPos().getY() + wall.getHeight();

    // Check for overlap and calculate penetration depth
    bool overlapX = ballRight > wallLeft && ballLeft < wallRight;
    bool overlapY = ballTop > wallBottom && ballBottom < wallTop;

    if (overlapX) {
        float overlapX1 = wallRight - ballLeft;
        float overlapX2 = ballRight - wallLeft;
        penetration.setX((overlapX1 < overlapX2) ? overlapX1 : -overlapX2);
    }
    if (overlapY) {
        float overlapY1 = wallTop - ballBottom;
        float overlapY2 = ballTop - wallBottom;
        penetration.setY((overlapY1 < overlapY2) ? overlapY1 : -overlapY2);
    }

    // Ensure there is actually a penetration before modifying penetration vector
    if (!overlapX) {
        penetration.setX(0);
    }
    if (!overlapY) {
        penetration.setY(0);
    }

    // Return the smallest penetration vector
    if (std::abs(penetration.getX()) < std::abs(penetration.getY())) {
        penetration.setY(0);
    } else {
        penetration.setX(0);
    }

    return penetration;
}

void Ball::handleCollision(const Wall& wall) {
    Vector oldVel = this->getVelocity();

    // Get the penetration vector (depth and direction)
    Vector penetration = this->getPenetrationVector(wall);

    // Move the ball out of the wall
    Vector currentPos = this->getPos();
    currentPos = currentPos + penetration;
    this->setPos(currentPos);

    // Invert the velocity along the penetration vector
    Vector normal = penetration.normalize();
    Vector newVel = (oldVel - 2 * oldVel.dot(normal) * normal) * wall.getCOR(); //the Cor 0-1 determine how much bounce
    this->setVelocity(newVel);
}

void Ball::updateWithDrag(double gravity, double fluidDensity, double dt){
    double referenceArea = M_PI*radius*radius;
    double dragCoefficient = 0.47f;

    // Calculate drag force
    double speed = velocity.magnitude(); // Calculate the speed of the object
    double dragForceMagnitude = 0.5 * dragCoefficient * fluidDensity * referenceArea * speed * speed;
    Vector dragForce = -1*velocity.normalize() * dragForceMagnitude; // Drag force opposes velocity

    // Calculate net force (including gravity and drag)
    Vector netForce = Vector(0, -mass * gravity, 0) + dragForce;

    // Update acceleration based on net force
    acceleration = netForce / mass;

    // Update velocity using acceleration
    velocity = velocity + acceleration * dt;
    
    // std::cout<<"\nDrag: ";
    // dragForce.display();
    // std::cout<<"Velocity: ";
    // velocity.display();
}

void Ball::move(float dt) {
    // Update position using velocity
    pos = pos + velocity * dt;
}