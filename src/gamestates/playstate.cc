#include <chrono>
#include <thread>
#include <cassert>

#include "gamestates/playstate.hh"
#include "settings.hh"
#include "map_reader.hh"
#include "player.hh"
#include "map.hh"

PlayState::PlayState(std::string map)
{
    if (!MapReader::set_size(map))
        throw std::logic_error("Could not load map '" + map + "'.");
    Map::init();
    Map::init_draw(0, 0, Settings::screen_width, Settings::screen_height);
    if (!MapReader::read_map(map))
        throw std::logic_error("Error reading map '" + map + "'.");
}

void PlayState::draw(sf::RenderWindow& w)
{
    Map::draw(w);

    sf::Text text;

    sf::Font f;
    f.loadFromFile("resources/GoodDog.otf");
    text.setFont(f);

    text.setString("Hey! How are you?");
    text.setPosition(42, 666);

    text.setCharacterSize(24);

    text.setColor(sf::Color::Blue);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    w.draw(text);

    std::this_thread::sleep_for(std::chrono::seconds(1));
}


void PlayState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
