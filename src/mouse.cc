#include <SFML/Window.hpp>

#include "mouse.hh"

std::pair<int, int> Mouse::get_mous_pos()
{
    sf::Vector2i position = sf::Mouse::getPosition();
    std::pair<int, int> p;
    p.first = position.x;
    p.second = position.y;
    return p;
}
