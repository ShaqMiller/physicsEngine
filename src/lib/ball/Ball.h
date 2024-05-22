#ifndef BALL_H
#define BALL_H

#include "../object/Object.h"
#include "../wall/Wall.h"

class Ball : public Object {
    private:
        double radius;
        sf::CircleShape shape;

    public:
        // Constructors
        Ball();
        Ball(double x, double y, double z, double radius);
        Ball(double x, double y, double z, Vector v, double radius);
        Ball(Vector pos, double radius);
        Ball(Vector pos, Vector v, double radius);

        // Destructor
        ~Ball();

        // Getter and setter for radius
        double getRadius() const;
        void setRadius(double r);

        // Override render function
        void render(sf::RenderWindow& window, float window_height) override;

        // Collision detection method
        bool checkCollision(const Wall& wall) const;
};

#endif // BALL_H