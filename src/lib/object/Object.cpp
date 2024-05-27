#include "Object.h"
#include <cmath>
#include <iostream>

//Constructors
Object::Object() : pos() ,velocity(),acceleration(),mass(1.0f),COR(0.1f),isKinematic(false){};
Object::Object(double x,double y,double z) : pos(x,y,z),velocity(),acceleration(),mass(1.0f),COR(0.1f),isKinematic(false){};
Object::Object(double x,double y,double z,Vector v): pos(x,y,z),velocity(v),acceleration(),mass(1.0f),COR(0.1f),isKinematic(false){};
Object::Object(Vector pos): pos(pos),velocity(),acceleration(),mass(1.0f),COR(0.1f),isKinematic(false){};
Object::Object(Vector pos,Vector v): pos(pos),velocity(v),acceleration(),mass(1.0f),COR(0.1f),isKinematic(false){}

// Destructor
Object::~Object() {}

//Getters & setters
Vector Object::getPos() const{ return this->pos;};
Vector Object::getVelocity() const{return this->velocity;};
Vector Object::getAcceleration() const{return this->acceleration;};
double Object:: getMass() const {return this->mass;};
double Object:: getCOR() const {return this->COR;};
bool Object:: getIsKinematic() const {return this->isKinematic;};

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
void Object::setMass(double m){
    this->mass = m;
}
void Object::setCOR(double val){
    this->COR = val;
}
void Object::setIsKinematic(bool val){
    this->isKinematic;
}

void Object::update(float dt) {
    // Update velocity using acceleration
    velocity = this->velocity + (acceleration * dt);  
    // Update position using velocity
    pos = this->pos + (this->velocity * dt);
}