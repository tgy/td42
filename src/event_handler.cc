#include <iostream>

#include "event_handler.hh"

void EventHandler::call_handler(sf::RenderWindow& w,
                                std::shared_ptr<GameState> g)
{
    if (std::shared_ptr<MenuState> m = dynamic_cast<std::shared_ptr<MenuState>>(g))
    {
        handle_menustate(w, m);
    }
    else if (PlayState* p = dynamic_cast<PlayState*>(g))
    {
        handle_playstate(w, p);
    }
    else
    {
        StartState* s = dynamic_cast<StartState*>(g);
        handle_startstate(w, s);
    }
}

void EventHandler::handle_menustate(sf::RenderWindow& w, MenuState*)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Q:
                        break;
                    case sf::Keyboard::W:
                        break;
                    case sf::Keyboard::E:
                        break;
                    case sf::Keyboard::Space:
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                }
                break;
            case sf::Event::Closed:
                w.close();
                return;
                break;
            default:
                break;
        }
    }
}
