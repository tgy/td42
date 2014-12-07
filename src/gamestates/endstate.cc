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
    static uint16_t count = 0;
    if (count > 1000)
        count = 0;
    w.clear();
    if (Player::get_life_nb() < 1)
        TextDrawer::display_lost(w);
    else
        TextDrawer::display_win(w);
    if (count < 450)
        TextDrawer::display_restart(w);
    count++;
}

void EndState::update(unsigned elapsed_ms)
{
    ++elapsed_ms;
}
