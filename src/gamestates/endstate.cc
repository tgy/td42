#include <stdexcept>
#include <climits>

#include "player.hh"
#include "text_drawer.hh"
#include "gamestates/endstate.hh"

EndState::EndState()
{
}

void EndState::draw(sf::RenderWindow& w)
{
    static unsigned count = 0;
    if (Player::get_life_nb() < 1)
        TextDrawer::display_lost(w);
    else
        TextDrawer::display_win(w);
    if (count < UINT_MAX / 2)
        TextDrawer::display_restart(w);
    count++;
}

void EndState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
