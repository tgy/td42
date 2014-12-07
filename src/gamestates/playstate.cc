#include <stdexcept>
#include <memory>
#include <cassert>
#include <iostream>

#include "gamestates/playstate.hh"
#include "settings.hh"
#include "map_reader.hh"
#include "player.hh"
#include "map.hh"
#include "text_drawer.hh"
#include "turrets/basic.hh"

PlayState::PlayState(std::string map)
{
    if (!MapReader::set_size(map))
        throw std::logic_error("Could not load map '" + map + "'.");
    Map::init();
    Map::init_draw(0, 0, Settings::screen_width, Settings::screen_height);
    if (!MapReader::read_map(map))
        throw std::logic_error("Error reading map '" + map + "'.");
    Map::turrets.push_front(std::make_shared<BasicTurret>(0, 0));
}

void PlayState::draw(sf::RenderWindow& w)
{
    Map::draw(w);
    //std::cout << "debug" << std::endl;
    TextDrawer::display_time(w);
    TextDrawer::display_lifes(w);
    TextDrawer::display_money(w);

    //sf::Text text;

    //sf::Font f;
    //f.loadFromFile("resources/GoodDog.otf");
    //text.setFont(f);

    //text.setString("Hey! How are you?");
    //text.setPosition(42, 666);

    //text.setCharacterSize(24);

    //text.setColor(sf::Color::Blue);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    //w.draw(text);

    //std::this_thread::sleep_for(std::chrono::seconds(1));
}


void PlayState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
