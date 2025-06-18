#include "Wall.h"

Wall::Wall() : Object(), width(100), height(20) {
    shape.setSize(sf::Vector2f(width, height));
}

Wall::Wall(double x, double y, double z, double width, double height)
    : Object(x, y, z), width(width), height(height) {
    shape.setSize(sf::Vector2f(width, height));
}

Wall::Wall(Vector pos, double width, double height)
    : Object(pos), width(width), height(height) {
    shape.setSize(sf::Vector2f(width, height));
}

Wall::~Wall() {}

void Wall::render(sf::RenderWindow& window, float window_height) {
    float inverted_y = window_height - pos.getY() - height; // Adjust for origin being at bottom-left
    shape.setPosition(sf::Vector2f(pos.getX(), inverted_y));
    window.draw(shape);
}

void Wall::update(float dt) {
    // Stationary object, no need to update position or velocity
}

double Wall::getWidth() const {
    return width;
}

double Wall::getHeight() const {
    return height;
}

void Wall::setWidth(double width) {
    this->width = width;
    shape.setSize(sf::Vector2f(width, height));
}

void Wall::setHeight(double height) {
    this->height = height;
    shape.setSize(sf::Vector2f(width, height));
}

// Update with drag method
void Wall::updateWithDrag(double gravity, double fluidDensity, double dt) {
    // Walls are static in this context, so no need to implement drag logic.
    // However, this satisfies the pure virtual requirement.
}
void Wall::move(float dt) {};
