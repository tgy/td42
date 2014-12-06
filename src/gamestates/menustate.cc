#include <stdexcept>
#include "gamestates/menustate.hh"

MenuState::MenuState()
{
  if (!logo_.loadFromFile("resources/logo.png"))
    throw std::logic_error("Could not load logo.");
  sf::Sprite s(logo_);
  logo_sprite_ = s;
}

void MenuState::draw(sf::RenderWindow& w)
{
  // Draw the sprite
  w.draw(logo_sprite_);
}


void MenuState::update(unsigned elapsed_ms)
{
  ++elapsed_ms;
}
