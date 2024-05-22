#ifndef OBJECT_H
#define OBJECT_H

#include "../vector/Vector.h"
#include <SFML/Graphics.hpp>

class Object {
protected:
    Vector pos;
    Vector velocity;
    Vector acceleration;

public:
    // Constructors
    Object();
    Object(double x, double y, double z);
    Object(double x, double y, double z, Vector v);
    Object(Vector pos);
    Object(Vector pos, Vector v);

    // Destructor
    ~Object();

    // Getters and setters
    Vector getPos() const;
    Vector getVelocity() const;
    Vector getAcceleration() const;

    void setVelocity(Vector v);
    void setPos(Vector v);
    void setAcceleration(Vector v);

    // Render function (pure virtual)
    virtual void render(sf::RenderWindow& window, float window_height) = 0;

    // Update function
    virtual void update(float dt); // dt: time step
};
#endif // OBJECT_H