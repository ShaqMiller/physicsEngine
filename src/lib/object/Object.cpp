#include "Object.h"
#include <cmath>
#include <iostream>

//Constructors
Object::Object() : pos() ,velocity(),acceleration(){};
Object::Object(double x,double y,double z) : pos(x,y,z),velocity(),acceleration(){};
Object::Object(double x,double y,double z,Vector v): pos(x,y,z),velocity(v),acceleration(){};
Object::Object(Vector pos): pos(pos),velocity(),acceleration(){};
Object::Object(Vector pos,Vector v): pos(pos),velocity(v),acceleration(){}

// Destructor
Object::~Object() {}

//Getters & setters
Vector Object::getPos() const{ return this->pos;};
Vector Object::getVelocity() const{return this->velocity;};
Vector Object::getAcceleration() const{return this->acceleration;};

//setters
void Object::setPos(Vector v){
    this->pos = v;
}
void Object::setVelocity(Vector v){
    this->velocity = v;
}
void Object::setAcceleration(Vector a){
    this->acceleration = a;
}

void Object::update(float dt) {
    // Update velocity using acceleration
    velocity = this->velocity + (acceleration * dt);
    // Update position using velocity
    pos = this->pos + (this->velocity * dt);
}