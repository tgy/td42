#include "gamestates/playstate.hh"
#include "settings.hh"
#include "map.hh"

PlayState::PlayState()
{
    Map::init(10, 10);
    Map::init_draw(0, 0, Settings::screen_width, Settings::screen_height);
}

void PlayState::draw(sf::RenderWindow& w)
{
  Map::draw(w);
}


void PlayState::update(unsigned elapsed_ms)
{
  ++elapsed_ms;
}
