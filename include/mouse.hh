#ifndef MOUSE_HH
# define MOUSE_HH

#include <tuple>
#include <SFML/Graphics.hpp>

class Mouse
{
    public:
        static std::pair<unsigned, unsigned>
               get_mouse_pos(const sf::RenderWindow& w);
        static bool is_cursor_in_bound(const sf::RenderWindow& w);
};

#endif /* MOUSE_HH */
