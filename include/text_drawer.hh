#ifndef TEXT_DRAWER_HH
# define TEXT_DRAWER_HH

#include <SFML/Graphics.hpp>

struct TextDrawer
{
    static void display_money(sf::RenderWindow& w);
    static void display_lifes(sf::RenderWindow& w);
    static void display_time(sf::RenderWindow& w);
    static void display_mouse_coords(sf::RenderWindow& w);
    static void display_mouse_coords_on_map(sf::RenderWindow& w);
};

#endif /* TEXT_DRAWER_HH */
