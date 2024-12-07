#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <string>

class Objects
{
    private:
        std::string name;
        float positionX;
        float positionY;
        float velocity;
        float mass;
        float radius;
        float acceleration;

    public:
        Objects(std::string name, float positionX, float positionY, float velocity, float mass, float radius, float accelaration);

        void setPositionX(float x);
        void setPositionY(float y);
        void setVelocity(float v);
        void setMass(float m);
        void setAcceleration(float a);

        std::string getName() const;
        float getPositionX() const;
        float getPositionY() const;
        float getVelocity() const;
        float getMass() const;
        float getAcceleration() const;
        float getRadius() const;
    
};

#endif
