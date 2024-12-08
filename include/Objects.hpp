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
        double angleOrbit;
        double timeStep;
        float revolution;

    public:
        Objects(std::string name, double mass, double radius, double distanceSun);

        void setDistanceSun(double d) { distanceSun = d; };
        void setPositionX(double x) { positionX = x; };
        void setPositionY(double y) { positionY = y;  };
        void setMass(double m) { mass = m; };
        void setAngleOrbit(double t) { angleOrbit = t; };
        void setRevolution(float i) { revolution += i; };
        void setTimeStep(double st) { timeStep = st; };
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
        double getAngleOrbit()   const { return angleOrbit; };
        double getTimeStep()     const { return timeStep; };
        float  getRevolution()   const { return revolution; };
        
        double F() {return acceleration * mass; } ;
        void initRevolution() { revolution = 0; };

        void updatePlanetOrbit();
};

#endif
