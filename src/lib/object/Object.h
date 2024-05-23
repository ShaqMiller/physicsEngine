#ifndef OBJECT_H
#define OBJECT_H

#include "../vector/Vector.h"
#include <SFML/Graphics.hpp>

class Object {
protected:
    Vector pos;
    Vector velocity;
    Vector acceleration;
    double mass;
    double COR;

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
    double getMass() const;
    double getCOR() const;

    void setMass(double m);
    void setVelocity(Vector v);
    void setPos(Vector v);
    void setAcceleration(Vector v);
    void setCOR(double val);

    // Render function (pure virtual)
    virtual void render(sf::RenderWindow& window, float window_height) = 0;
    virtual void updateWithDrag(double gravity,  double fluidDensity, double dt) = 0;
    virtual void move(float dt) =0; // dt: time step

    // Update function
    virtual void update(float dt); // dt: time step

};
#endif // OBJECT_H