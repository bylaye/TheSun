#include <Objects.hpp>

Objects::Objects(std::string name, double mass, double radius, double distanceSun)
    :name(name), mass(mass), radius(radius), distanceSun(distanceSun){};


void Objects::setVelocity(double G, double M, double d)
{
    velocity = std::sqrt((G*M)/d);
}


void Objects::setAcceleration(double d)
{
    acceleration = std::pow(velocity, 2) / d;
}

