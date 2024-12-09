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
    Objects& mercury = Planets[3];

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
        int i = 100;
		for (size_t p = 1; p < Planets.size(); p++) {
		    auto& planet = Planets[p];
		    planet.setTimeStep(TIME_STEP);
		    planet.updatePlanetOrbit();
		    output << planet.getName() << " : " << planet.getRevolution() << "\n";


            planet.setRadiusScale(13926800.0);
            sf::CircleShape sunShape = sun.getShape();
            planet.setShapeRadius(planet.getRadius() / planet.getRadiusScale() * 5);
            planet.setShapePosition(sunShape.getPosition().x+i, sunShape.getPosition().y);
            planet.setShapeOrigin(planet.getShape().getRadius(), planet.getShape().getRadius() );
            i += 55;
		}
		infoText.setString(output.str());
		usleep(50000);
        /*
        mercury.setRadiusScale(13926800.0);
        sf::CircleShape sunShape = sun.getShape();
        mercury.setShapeRadius(mercury.getRadius() / mercury.getRadiusScale() * 5);
        mercury.setShapePosition(sunShape.getPosition().x+100, sunShape.getPosition().y);
        mercury.setShapeOrigin(mercury.getShape().getRadius(), mercury.getShape().getRadius() );
        //mercury.setShapeOrigin(sun.getShape().getPosition().x, sun.getShape().getPosition().y );
        */
		window.clear();

		window.setView(simulationView);
		window.draw(simulationBackground);
        //sun.draw(window);
        
		for (Objects p : Planets) {
            p.draw(window);
            p.getName();
        }
        //mercury.draw(window);
	
		infoView.setViewport(sf::FloatRect(0.7f, 0.f, 0.3f, 1.f));
        window.setView(infoView);
        window.draw(infoBackground);
        window.draw(infoText);
        

		window.display();

	}    

    std::cout << " x: " << sun.getShape().getPosition().x  << " y: "<< sun.getShape().getPosition().y<<"\n";
    std::cout << "mercury x: " << mercury.getShape().getPosition().x  << " y: "<< mercury.getShape().getPosition().y<<"\n";
    std::cout << "mercury r: " << mercury.getShape().getRadius()  << " y: "<< mercury.getShape().getPosition().y<<"\n";
   

    return 0;

}

