#include <Objects.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <sstream>
#include <unistd.h>

int main(){
    const float mapWidth = 1200.0f;
    const float mapHeight = 800.0f;
    const float scale = 10.0f;
    
    sf::RenderWindow window(sf::VideoMode(mapWidth, mapHeight), "Star Map Simulation");
    sf::View simulationView(sf::FloatRect(0, 0, mapWidth * 0.7f, mapHeight));
    sf::View infoView(sf::FloatRect(mapWidth * 0.7f, 0, mapWidth * 0.3f, mapHeight));
    
    sf::RectangleShape simulationBackground(sf::Vector2f(mapWidth * 0.7f, mapHeight));
    simulationBackground.setFillColor(sf::Color(30, 30, 60));
    
    sf::RectangleShape infoBackground(sf::Vector2f(mapWidth * 0.3f, mapHeight));
    infoBackground.setFillColor(sf::Color::Green);
    infoBackground.setPosition(mapWidth * 0.7f, 0);

    std::vector<Objects> Planets;
    const PLANET& Sun = PlanetVector[0];
    float TIME_STEP = 3600*24;
 
    //for (const star::Planet& p : star::Planets)
    for (const PLANET& p : PlanetVector)
    {
        Objects planet(p.name, p.mass, p.radius, p.distanceSun, p.color);
        planet.setVelocity(G, Sun.mass, planet.getDistanceSun());
        planet.setAcceleration(p.distanceSun);
        planet.setPositionX(planet.getDistanceSun());
        planet.setPositionY(0);
        planet.setTimeStep(TIME_STEP);
        Planets.push_back(planet);
    }
	
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        return -1; 
    }

    sf::Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(18);
    infoText.setFillColor(sf::Color::Blue);
    infoText.setPosition(mapWidth * 0.7f + 10, 10);

    Objects sun = Planets[0];    

    sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
		    if (event.type == sf::Event::Closed) {
		        window.close();
		    }
		    if (event.type == sf::Event::KeyPressed) {
		        if (event.key.code == sf::Keyboard::Up) {
		            TIME_STEP = std::min(TIME_STEP + 3600.0f, 3600.0f * 24 * 365);
		        } else if (event.key.code == sf::Keyboard::Down) {
		            TIME_STEP = std::max(3600.0f, TIME_STEP - 3600);
		        }
		    }
		}
		
		

		// Mettre à jour les informations des planètes
		std::ostringstream output;
		output << "Time Step: " << TIME_STEP << "\n";
		output << "Revolution:" << "\n";

		for (size_t p = 1; p < Planets.size(); p++) {
		    auto& planet = Planets[p];
		    planet.setTimeStep(TIME_STEP);
		    planet.updatePlanetOrbit();
		    output << planet.getName() << " : " << planet.getRevolution() << "\n";
		}
		infoText.setString(output.str());
		usleep(50000);

		window.clear();

		window.setView(simulationView);
		window.draw(simulationBackground);
        sun.draw(window);
	
		infoView.setViewport(sf::FloatRect(0.7f, 0.f, 0.3f, 1.f));
        window.setView(infoView);
        window.draw(infoBackground);
        window.draw(infoText);
        

		window.display();

	}    

    std::cout << " x: " << sun.getShape().getPosition().x  << " y: "<< sun.getShape().getPosition().y;
   

    return 0;

}

