#include <Objects.hpp>

Objects::Objects(std::string name, float positionX, float positionY, float velocity, float mass, float radius)
    :name(name), positionX(positionX), positionY(positionY), velocity(velocity), mass(mass), radius(radius) {};


std::string Objects::getName() const
{
    return name;
}

float Objects::getPositionX() const
{
    return positionX;
}

float Objects::getPositionY() const
{
    return positionY;
}


float Objects::getVelocity() const
{
    return velocity;
}

float Objects::getMass() const
{
    return mass;
}

float Objects::getAcceleration() const
{
    return acceleration;
}

float Objects::getRadius() const
{
    return radius;
}


void Objects::setPositionX(float x)
{
    positionX = x;
}

void Objects::setPositionY(float y)
{
    positionY = y;
}

void Objects::setVelocity(float v)
{
    velocity = v;
}

void Objects::setMass(float m)
{
    mass = m;
}

void Objects::setAcceleration(float a)
{
    acceleration = a;
}

