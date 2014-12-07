#include <stdexcept>
#include "gamestates/menustate.hh"

MenuState::MenuState()
{
}

void MenuState::draw(sf::RenderWindow& w)
{
    w.clear();
}

void MenuState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
