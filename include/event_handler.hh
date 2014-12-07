#ifndef EVENT_HANDLER_HH
# define EVENT_HANDLER_HH

#include <SFML/Graphics.hpp>

class EventHandler
{
    public:
        static void call_handler(sf::RenderWindow& w);
};

#endif /* EVENT_HANDLER_HH */
