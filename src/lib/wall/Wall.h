#ifndef WALL_H
#define WALL_H

#include "../object/Object.h"

class Wall : public Object {
private:
    double width;
    double height;
    sf::RectangleShape shape; // SFML shape for rendering

public:
    // Constructors
    Wall();
    Wall(double x, double y, double z, double width, double height);
    Wall(Vector pos, double width, double height);

    // Destructor
    virtual ~Wall(); // Add virtual destructor
    //~Wall();

    // Render method override
    void render(sf::RenderWindow& window, float window_height) override;

    // Update method override
    void update(float dt) override;

    // Getters and setters for width and height
    double getWidth() const;
    double getHeight() const;
    void setWidth(double width);
    void setHeight(double height);

    // Update with drag method override
    void updateWithDrag(double gravity, double fluidDensity, double dt) override;
    void move(float dt) override;
};

#endif // WALL_H