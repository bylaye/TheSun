#include <Objects.hpp>
#include <iostream>

namespace star 
{
    
    struct Planet
    {
        double mass; // kg
        double radius; // m
        double distanceSun; // m
    };
    
    const Planet Mercury = {3.3011e23, 2.4397e6, 5.791e10};
    const Planet Venus   = {4.8675e24, 6.0518e6, 1.082e11};
    const Planet Earth   = {5.9724e24, 6.3710e6, 1.496e11};
    const Planet Mars    = {6.4171e23, 3.3895e6, 2.279e11};
    const Planet Jupiter = {1.8982e27, 6.9911e7, 7.785e11};
    const Planet Saturn  = {5.6834e26, 5.8232e7, 1.433e12};
    const Planet Uranus  = {8.6810e25, 2.5362e7, 2.877e12};
    const Planet Neptune = {1.0241e26, 2.4622e7, 4.503e12};    

    const Planet Sun = {1.989e30, 6.9634e8, 0.0}; 
    const double G = 6.674e-11;
}


int main(){
    Objects earth("Earth", star::Earth.mass, star::Earth.radius, star::Earth.distanceSun);
    earth.setVelocity(star::G, star::Sun.mass, earth.getDistanceSun());
    earth.setAcceleration(star::Earth.distanceSun);
    earth.setPositionX(111);
    earth.setPositionY(222);
    std::cout << earth.getPositionX() << earth.getName()<< std::endl;
//    std::cout << earth.getVelocity() << std::endl;
    std::cout << earth.getAcceleration() << std::endl;
    return 0;
}

