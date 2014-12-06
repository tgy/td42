#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "map.hh"
#include "pathfinding.hh"

int main()
{
    Map::init(10, 10);
    Map::print(std::cout);

    auto path = pathfind(std::make_pair(0, 0), std::make_pair(7, 9));
    for (const auto& node : path)
        Map::cells[node.first][node.second] = CellType::Tower;
    Map::print(std::cout);
    return 0;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "TD42");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("resources/logo.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Start the game loop
    while (window.isOpen())
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
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
