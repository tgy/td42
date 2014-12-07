//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "mouse.hh"
#include "settings.hh"

std::pair<int, int> Mouse::get_mous_pos(const sf::RenderWindow& w)
{
    sf::Vector2i position = sf::Mouse::getPosition(w);
    std::pair<int, int> p;
    p.first = position.x * Settings::screen_width / w.getSize().x;
    p.second = position.y * Settings::screen_height / w.getSize().y;
    return p;
}
