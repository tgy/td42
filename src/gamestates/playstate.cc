#include "gamestates/playstate.hh"
#include "map.hh"

PlayState::PlayState()
{
    Map::init(10, 10);
}

void PlayState::draw(sf::RenderWindow& w)
{
  Map::draw(w);
}


void PlayState::update(unsigned elapsed_ms)
{
  ++elapsed_ms;
}
