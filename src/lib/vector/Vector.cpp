#include "Vector.h"
#include <cmath>
#include <iostream>

//Constructors
Vector::Vector() : x(0.0),y(0.0),z(0.0) {};
Vector::Vector(double i,double j,double k) : x(i),y(j),z(k){};

// Destructor
Vector::~Vector() {}

//Getters & setters
double Vector::getX() const{
    return x;
};

//Getters & setters
double Vector::getY() const{
    return y;
};

//Getters & setters
double Vector::getZ() const{ 
    return z;
}

//setters
void Vector::setX(double val) {x=val;}
void Vector::setY(double val) {y=val;}
void Vector::setZ(double val) {z=val;}


//functions
void Vector::display(){
    std::cout << "Vector<" << x << ", " << y << ", " << z << ">" << std::endl;
}

double Vector::magnitude() const {
    if(x==0 && y==0 && z==0) return 0;
    return(std::sqrt((x*x) + (y*y) + (z*z)));
}

Vector Vector::normalize() const{
    double mag = this->magnitude();
    return Vector(x / mag, y / mag, z / mag);
}

Vector Vector::add(const Vector &other) const{
    return Vector(this->getX()+other.getX(), this->getY()+other.getY(),this->getZ()+other.getZ());
}


Vector Vector::subtract(const Vector &other) const{
    return Vector(this->getX()+ (other.getX()*-1), this->getY()+(other.getY()*-1),this->getZ()+(other.getZ()*-1));
}

Vector Vector::scale(int scale) const{
    return  Vector(this->getX() * scale, this->getY() * scale,this->getZ() * scale);
}

Vector Vector::cross(const Vector &other) const {
    return Vector(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

double Vector::dot(const Vector &other) const {
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

// Operator overloads
Vector Vector::operator+(const Vector &other) const {
    return this->add(other);
}
Vector Vector::operator-(const Vector &other) const {
    return this->subtract(other);
}

Vector Vector::operator*(const double scalar) const {
    return Vector(this->x*scalar,this->y*scalar,this->z*scalar);
}
Vector Vector::operator*(const Vector &other) const {
    return Vector(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector operator*(double scalar, const Vector &vec) {
    return Vector(vec.x * scalar, vec.y * scalar, vec.z * scalar);
}
