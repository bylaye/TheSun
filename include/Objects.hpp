#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <string>
#include <cmath>
#include <iostream>

class Objects
{
    private:
        std::string name;
        double positionX;
        double positionY;
        double velocity;
        double mass;
        double radius;
        double acceleration;
        double distanceSun;

    public:
        Objects(std::string name, double mass, double radius, double distanceSun);

        void setDistanceSun(double d) { distanceSun = d; };
        void setPositionX(double x) { positionX = x; };
        void setPositionY(double y) { positionY = y;  };
        void setMass(double m) { mass = m; };
        void setVelocity(double G, double M, double d);
        void setAcceleration(double d);

        std::string getName()    const { return name; };
        double getMass()         const { return mass; };
        double getRadius()       const { return radius; };
        double getDistanceSun()  const { return distanceSun; };
        double getPositionX()    const { return positionX; };
        double getPositionY()    const { return positionY; };
        double getVelocity()     const { return velocity; };
        double getAcceleration() const { return acceleration; };
        
        double F() {return acceleration * mass; } ;    
};

#endif
