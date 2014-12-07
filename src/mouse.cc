//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "mouse.hh"
#include "settings.hh"

std::pair<unsigned, unsigned> Mouse::get_mouse_pos(const sf::RenderWindow& w)
{
    sf::Vector2i position = sf::Mouse::getPosition(w);
    std::pair<unsigned, unsigned> p;
    p.first = position.x * Settings::screen_width / w.getSize().x;
    p.second = position.y * Settings::screen_height / w.getSize().y;
    return p;
}

bool Mouse::is_cursor_in_bound(const sf::RenderWindow& w)
{
    std::pair<unsigned, unsigned> p = get_mouse_pos(w);;
    //return p.first < tmp - Settings::screen_width * 2 &&
           //p.second < tmp - Settings::screen_height * 2;
    return !(p.first > Settings::screen_width ||
             p.second > Settings::screen_height);
}
