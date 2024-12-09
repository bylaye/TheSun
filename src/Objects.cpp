#include <Objects.hpp>

Objects::Objects(std::string name, double mass, double radius, double distanceSun, sf::Color shapeColor)
    :name(name), mass(mass), radius(radius), distanceSun(distanceSun), shapeColor(shapeColor)
{
    //shape.setRadius(radius);
    //shape.setOrigin(radius, radius);
    //shape.setPosition(positionX, positionY);
    shape.setFillColor(shapeColor);
    shape.setScale(1, 1.2);
    shape.setRadius(70);
    shape.setOrigin(70, 100);
    shape.setPosition(300, 300);
    revolution = 0;
    angleOrbit = 0;
};


void Objects::setVelocity(double G, double M, double d)
{
    velocity = std::sqrt((G*M)/d);
}


void Objects::setAcceleration(double d)
{
    acceleration = std::pow(velocity, 2) / d;
}


void Objects::updatePlanetOrbit()
{
    double tetaAngleOrbit = (velocity * timeStep) / distanceSun;
    
    angleOrbit += tetaAngleOrbit;
    setRevolution(tetaAngleOrbit / (2 * M_PI));
    if (angleOrbit >= 2 * M_PI) 
    { 
        angleOrbit -= 2 * M_PI;
        //setRevolution(1);
    }
    double x = distanceSun  * std::cos(angleOrbit);
    double y = distanceSun  * std::sin(angleOrbit);

    setAngleOrbit(angleOrbit);
    setPositionX(x);
    setPositionY(y);
             
}
