#include "Ball.h"
#include "../wall/Wall.h"

// Default constructor
Ball::Ball() : Object(), radius(1.0) {
    // Initialize the circle shape
    shape.setRadius(1);
    shape.setFillColor(sf::Color::White);
}

// Constructor with position and radius
Ball::Ball(double x, double y, double z, double r) : Object(x, y, z), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
}

// Constructor with position, velocity, and radius
Ball::Ball(double x, double y, double z, Vector v, double r) : Object(x, y, z, v), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
}

// Constructor with position vector and radius
Ball::Ball(Vector pos, double r) : Object(pos), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
}

// Constructor with position vector, velocity vector, and radius
Ball::Ball(Vector pos, Vector v, double r) : Object(pos, v), radius(r) {
    // Initialize the circle shape
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
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
    // Check if the ball has collided with the top of the wall (floor)
    if (pos.getY() - radius <= wall.getPos().getY() + wall.getHeight()) {
        return true;
    }
    return false;
}