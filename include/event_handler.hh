#ifndef EVENT_HANDLER_HH
# define EVENT_HANDLER_HH

#include <SFML/Graphics.hpp>

#include "gamestate.hh"
#include "gamestates/menustate.hh"
#include "gamestates/playstate.hh"
#include "gamestates/startstate.hh"

class EventHandler
{
    public:
        static void call_handler(sf::RenderWindow& w,
                                 std::shared_ptr<GameState> g);
        static void handle_menustate(sf::RenderWindow& w);
        static void handle_playstate(sf::RenderWindow& w,
                                     std::shared_ptr<PlayState>);
        static void handle_startstate(sf::RenderWindow& w);
};

#endif /* EVENT_HANDLER_HH */
