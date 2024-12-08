#ifndef SYSTEMMAP_HPP
#define SYSTEMMAP_HPP

#include <SFML/Graphics.hpp>

class SystemMap
{
    private:
        sf::RenderWindow& window;
        float width;
        float height;
        float scale;
        sf::Vector2f center;

    public:
        SystemMap(sf::RenderWindow& win, float width, float height, float scale);

        void draw();
};

#endif
