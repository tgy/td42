#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <unistd.h>
#include <time.h>

#include "settings.hh"
#include "gamestate.hh"
#include "gamestates/startstate.hh"
#include "map.hh"
#include "pathfinding.hh"
#include "map_reader.hh"
#include "event_handler.hh"

#define FPS 60

std::list<std::shared_ptr<GameState>> GameState::stack;

void init()
{
    std::shared_ptr<StartState> ptr = std::make_shared<StartState>();
    GameState::stack.push_back(ptr);
    srand(time(NULL));
}

int main()
{
    // Create the main window
    Settings::screen_width = 1368;
    Settings::screen_height = 768;
    sf::RenderWindow window(sf::VideoMode(Settings::screen_width,
                Settings::screen_height), "TD42");
    // Init
    init();
    const double step0 = 1;
    const double step = step0 / FPS;
    std::chrono::time_point<std::chrono::system_clock> start_time;
    std::chrono::time_point<std::chrono::system_clock> save_time;
    std::chrono::duration<double> elapsed;
    double elapsed_time = step;
    // Start the game loop
    for (unsigned t; window.isOpen() && !GameState::stack.empty();)
    {
        start_time = std::chrono::system_clock::now();
        auto state = GameState::stack.back();
        // Process events
        EventHandler::call_handler(window, state);
        // Clear screen
        window.clear();
        state->update(elapsed_time * 1000);
        state->draw(window);
        // Update the window
        window.display();
        save_time = std::chrono::system_clock::now();
        elapsed = save_time - start_time;
        elapsed_time = elapsed.count();
        if (elapsed_time < step)
        {
            t = (step - elapsed_time) * 1000;
            double tot = t;
            elapsed_time += tot / 1000;
            usleep(t);
        }

    }
    return EXIT_SUCCESS;
}
