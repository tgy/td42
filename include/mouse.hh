#ifndef MOUSE_HH
# define MOUSE_HH

#include <tuple>
#include <SFML/Graphics.hpp>

class Mouse
{
    public:
        static std::pair<int, int> get_mous_pos(const sf::RenderWindow& w);
};

#endif /* MOUSE_HH */
