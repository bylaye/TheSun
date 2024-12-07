#include <Objects.hpp>

Objects::Objects(std::string name, double mass, double radius, double distanceSun)
    :name(name), mass(mass), radius(radius), distanceSun(distanceSun){};


void Objects::setVelocity(double v)
{
    velocity = v;
}


void Objects::setAcceleration(double a)
{
    acceleration = a;
}

