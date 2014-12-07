#include <iostream>

#include "turrets/basic.hh"
#include "turrets/super.hh"
#include "turrets/sniper.hh"
#include "event_handler.hh"

#include "gamestates/endstate.hh"

void EventHandler::call_handler(sf::RenderWindow& w,
                                std::shared_ptr<GameState> g)
{
    if (std::shared_ptr<MenuState> m = std::dynamic_pointer_cast<MenuState>(g))
        handle_menustate(w);
    else if (
        std::shared_ptr<PlayState> p = std::dynamic_pointer_cast<PlayState>(g))
        handle_playstate(w, p);
    else if (
        std::shared_ptr<StartState> s = std::dynamic_pointer_cast<StartState>(
            g))
    {
        handle_startstate(w);
    }
    else if (
        std::shared_ptr<EndState> e = std::dynamic_pointer_cast<EndState>(g))
        handle_endstate(w);
}

void EventHandler::handle_menustate(sf::RenderWindow& w)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                w.close();
                return;
                break;
            default:
                break;
        }
    }
}

void EventHandler::handle_playstate(sf::RenderWindow& w,
                                    std::shared_ptr<PlayState> s)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        s->exit_insert_mode();
                        break;
                    case sf::Keyboard::Q:
                        s->insert_mode(std::make_shared<BasicTurret>(0, 0));
                        break;
                    case sf::Keyboard::W:
                        s->insert_mode(std::make_shared<SniperTurret>(0, 0));
                        break;
                    case sf::Keyboard::E:
                        s->insert_mode(std::make_shared<SuperTurret>(0, 0));
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
                    s->exit_insert_mode_and_create();
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
void EventHandler::handle_startstate(sf::RenderWindow& w)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                w.close();
                return;
                break;
            default:
                break;
        }
    }
}

void EventHandler::handle_endstate(sf::RenderWindow& w)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                w.close();
                return;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        w.close();
                        return;
                    case sf::Keyboard::Return:
                        while (not GameState::stack.empty())
                            GameState::stack.pop_back();
                        GameState::stack.push_back(
                            std::make_shared<StartState>());
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}
