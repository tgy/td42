#include <iostream>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "settings.hh"
#include "gamestate.hh"
#include "gamestates/startstate.hh"

std::list<std::shared_ptr<GameState>> GameState::stack;

void init()
{
    std::shared_ptr<StartState> ptr = std::make_shared<StartState>();
    //std::shared_ptr<PlayState> ptr = std::make_shared<PlayState>();
    GameState::stack.push_back(ptr);
}

int main()
{
    // Create the main window
    Settings::screen_width = 1000;
    Settings::screen_height = 600;
    sf::RenderWindow window(sf::VideoMode(Settings::screen_width,
                                          Settings::screen_height), "TD42");
    // Init
    init();
    // Start the game loop
    while (window.isOpen() && !GameState::stack.empty())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
        }
        // Clear screen
        window.clear();
        auto state = GameState::stack.back();
        state->update(42);;
        state->draw(window);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
