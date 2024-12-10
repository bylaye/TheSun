#include <Objects.hpp>

Objects::Objects(std::string name, double mass, double radius, double distanceSun, sf::Color shapeColor)
    :name(name), mass(mass), radius(radius), distanceSun(distanceSun), shapeColor(shapeColor)
{
    setRadiusScale(radius / 50);
    setDistanceSunScale(distanceSun / 50);
    shape.setRadius(radius / radiusScale);
    shape.setOrigin(radius/radiusScale, radius/radiusScale);
    //shape.setPosition(positionX / , positionY);
    shape.setFillColor(shapeColor);
    shape.setScale(1, 1.3);
    //shape.setRadius(70);
    //shape.setOrigin(70, 100);
    shape.setPosition(100, 400);
    revolution = 0;
    angleOrbit = 0;
};


const std::vector<PLANET> PlanetVector {
    {"Sun",     1.989e30, 6.9634e8, 0.0, sf::Color::Yellow},
    {"Mercury", 3.3011e23, 2.4397e6, 5.791e10, sf::Color::Green}, // Planet 1
    {"Venus",   4.8675e24, 6.0518e6, 1.082e11, sf::Color::Yellow}, // Planet 2
    {"Earth",   5.9724e24, 6.3710e6, 1.496e11, sf::Color::Blue}, // Planet 3: Our Planet
    {"Mars",    6.4171e23, 3.3895e6, 2.279e11, sf::Color::Red}, // Planet 4
    {"Jupiter", 1.8982e27, 6.9911e7, 7.785e11, sf::Color(100, 50, 50)}, // Planet 5
    {"Saturn",  5.6834e26, 5.8232e7, 1.433e12, sf::Color(100, 10, 150)}, // Planet 6
    {"Uranus",  8.6810e25, 2.5362e7, 2.877e12, sf::Color(100, 50, 200, 90)}, // Planet 7
    {"Neptune", 1.0241e26, 2.4622e7, 4.503e12, sf::Color(0, 0, 200, 90)}, // Planet 8
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
