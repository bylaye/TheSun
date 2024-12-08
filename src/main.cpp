#include <Objects.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SystemMap.hpp>
#include <vector>
#include <cmath>

namespace star 
{    
    const double G = 6.674e-11;

    struct Planet
    {
        std::string name;
        double mass; // kg
        double radius; // m
        double distanceSun; // m
    };

    const std::vector<Planet> Planets {
        {"Sun",     1.989e30, 6.9634e8, 0.0},
        {"Mercury", 3.3011e23, 2.4397e6, 5.791e10}, // Planet 1
        {"Venus",   4.8675e24, 6.0518e6, 1.082e11}, // Planet 2
        {"Earth",   5.9724e24, 6.3710e6, 1.496e11}, // Planet 3: Our Planet
        {"Mars",    6.4171e23, 3.3895e6, 2.279e11}, // Planet 4
        {"Jupiter", 1.8982e27, 6.9911e7, 7.785e11}, // Planet 5
        {"Saturn",  5.6834e26, 5.8232e7, 1.433e12}, // Planet 6
        {"Uranus",  8.6810e25, 2.5362e7, 2.877e12}, // Planet 7
        {"Neptune", 1.0241e26, 2.4622e7, 4.503e12}, // Planet 8
    };

}


int main(){
    const float mapWidth = 1200.0f;
    const float mapHeight = 680.0f;
    const float scale = 10.0f;
    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");

    std::vector<Objects> Planets;
    const star::Planet& Sun = star::Planets[0];
    float TIME_STEP = 3600*24;
 
    for (const star::Planet& p : star::Planets)
    {
        Objects planet(p.name, p.mass, p.radius, p.distanceSun);
        planet.setVelocity(star::G, Sun.mass, planet.getDistanceSun());
        planet.setAcceleration(p.distanceSun);
        planet.setPositionX(planet.getDistanceSun());
        planet.setPositionY(0);
        planet.setTimeStep(TIME_STEP);
        Planets.push_back(planet);
    }

    /*       
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }
    */
    for (int i=0; i< 300; i++)
    {
        std::cout << i << " "; 
        for (size_t p=1 ; p < Planets.size(); p++)
        {
            auto& planet = Planets[p];
            planet.updatePlanetOrbit(); 
            std::cout << planet.getName()<< " : " << planet.getRevolution()<< " ";
        }
        std::cout << std::endl;
    }

    return 0;

}

