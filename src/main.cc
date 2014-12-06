#include <iostream>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "gamestate.hh"
#include "gamestates/menustate.hh"

std::list<std::shared_ptr<GameState>> GameState::stack;

void init()
{
  std::shared_ptr<GameState> ptr(new MenuState());
  GameState::stack.push_back(ptr);
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "TD42");
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
                window.close();
        }
        // Clear screen
        window.clear();
        GameState::stack.back()->update(42);;
        GameState::stack.back()->draw(window);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
