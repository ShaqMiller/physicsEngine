#ifndef VECTOR_H
#define VECTOR_H

#include <iosfwd> // Forward declaration of std::ostream

class Vector{
    private:
        double x;
        double y;
        double z;
    
    public:
        //Constructors
        Vector();
        Vector(double i,double j,double k);

        //Destructure
        ~Vector();

        //getters and setters
        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(double val);
        void setY(double val);
        void setZ(double val);

        void display();

        double magnitude() const;
        Vector normalize() const;
        Vector add(const Vector &other) const;
        Vector subtract(const Vector &other) const;
        
        Vector scale(int scale) const;
        double dot(const Vector &other) const;
        Vector cross(const Vector &other) const;

        // + Operator overloads
        Vector operator+(const Vector &other) const; 
        // - Operator overloads
        Vector operator-(const Vector &other) const; 
        
        // * Operator overloads
        Vector operator*(double scalar) const;
        Vector operator*(const Vector &other) const;
        
        // / Operator overloads
        Vector operator/(double scalar) const;
        
        // Friend function for scalar multiplication with scalar on the left
        friend Vector operator*(double scalar, const Vector &vec);

};

#endif // VECTOR