#include <iostream>

#include "event_handler.hh"

void EventHandler::call_handler(sf::RenderWindow& w)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                if (event.type == sf::Event::KeyPressed)
                {
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
