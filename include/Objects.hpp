#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

const double G = 6.674e-11;

typedef struct
{
    std::string name;
    // Real value
    double mass; // mass in kg
    double radius; // meter
    double distanceSun; // meter
    // Simulation parameter
    sf::Color color;
    float shapeRadius;
    float shapeDistanceSun;
} PLANET;

extern const std::vector<PLANET> PlanetVector;

class Objects
{
    private:
        std::string name;
        double positionX;
        double positionY;
        double velocity;
        double mass;
        double radius;
        double radiusScale;
        double acceleration;
        double distanceSun;
        double distanceSunScale;
        double angleOrbit;
        double timeStep;
        float revolution;
        sf::CircleShape shape;
        sf::Color shapeColor;
        sf::Vector2f shapeCenter;
        float shapeDistanceSun;

    public:
        Objects(std::string name, double mass, double radius, double distanceSun, sf::Color shapeColor);

        void setDistanceSun(double d) { distanceSun = d; };
        void setDistanceSunScale(double ds) { distanceSunScale = ds; };
        void setPositionX(double x) { positionX = x; };
        void setPositionY(double y) { positionY = y;  };
        void setMass(double m) { mass = m; };
        void setRadiusScale(double rs) { radiusScale = rs; };
        void setAngleOrbit(double t) { angleOrbit = t; };
        void setRevolution(float i) { revolution += i; };
        void setTimeStep(double st) { timeStep = st; };
        void setVelocity(double G, double M, double d);
        void setAcceleration(double d);
        void setShapeCenter(sf::Vector2f center) { shapeCenter = center; };
        void setShapeRadius(float r) { shape.setRadius(r); };
        void setShapePosition(sf::Vector2f pos ) { shape.setPosition(shapeCenter + pos); };
        void setShapeOrigin(float x, float y) { shape.setOrigin(x, y); };
        void setShapeDistanceSun(float d) { shapeDistanceSun = d; };
        //void setOrbitPosition(float d) { shapeDistanceSun = d; };

        std::string getName()         const { return name; };
        double getMass()              const { return mass; };
        double getRadius()            const { return radius; };
        double getRadiusScale()       const { return radiusScale; };
        double getDistanceSun()       const { return distanceSun; };
        double getDistanceSunScale()  const { return distanceSunScale; };
        double getPositionX()         const { return positionX; };
        double getPositionY()         const { return positionY; };
        double getVelocity()          const { return velocity; };
        double getAcceleration()      const { return acceleration; };
        double getAngleOrbit()        const { return angleOrbit; };
        double getTimeStep()          const { return timeStep; };
        float  getRevolution()        const { return revolution; };
        sf::CircleShape  getShape()   const { return shape; };
        
        double F() {return acceleration * mass; } ;
        void initRevolution() { revolution = 0; };

        void updatePlanetOrbit();
        void draw(sf::RenderWindow& window){ window.draw(shape); };
};

#endif
