#include "gamestates/playstate.hh"
#include "settings.hh"
#include "map_reader.hh"
#include "map.hh"

PlayState::PlayState(std::string map)
{
  if (!MapReader::set_size(map))
    throw std::logic_error("Could not load map '" + map + "'.");
    Map::init();
    Map::init_draw(0, 0, Settings::screen_width, Settings::screen_height);
  if (!MapReader::read_map(map))
    throw std::logic_error("Error reading map '" + map + "'.");
  //Map::print(std::cout);
}

void PlayState::draw(sf::RenderWindow& w)
{
    Map::draw(w);
}


void PlayState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
