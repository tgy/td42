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
#include "turrets/sniper.hh"
#include "turrets/super.hh"
#include "mobs/foot_soldier.hh"
#include "mobs/horse_soldier.hh"
#include "mobs/tank_soldier.hh"

PlayState::PlayState(std::string map)
{
    if (!MapReader::set_size(map))
        throw std::logic_error("Could not load map '" + map + "'.");
    Map::init();
    Map::init_draw(0, 0);
    if (!MapReader::read_map(map))
        throw std::logic_error("Error reading map '" + map + "'.");
    for (unsigned i = 0; i < 5; ++i)
        Map::turrets.push_front(std::make_shared<BasicTurret>(0, i));
    for (unsigned i = 0; i < 5; ++i)
        Map::turrets.push_front(std::make_shared<SniperTurret>(1, i));
    for (unsigned i = 0; i < 5; ++i)
        Map::turrets.push_front(std::make_shared<SuperTurret>(2, i));
    for (unsigned i = 0; i < 5; ++i)
        Map::ennemies.push_front(std::make_shared<FootSoldier>(3, i));
    for (unsigned i = 0; i < 5; ++i)
        Map::ennemies.push_front(std::make_shared<HorseSoldier>(4, i));
    for (unsigned i = 0; i < 5; ++i)
        Map::ennemies.push_front(std::make_shared<TankSoldier>(5, i));
    Player::init(42, 10, std::chrono::system_clock::now());
}

void PlayState::draw(sf::RenderWindow& w)
{
    Map::draw(w);
    //std::cout << "debug" << std::endl;
    TextDrawer::display_time(w);
    TextDrawer::display_lifes(w);
    TextDrawer::display_money(w);
    TextDrawer::display_mouse_coords(w);
    TextDrawer::display_mouse_coords_on_map(w);

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
