#include <cassert> //remove_a_life()

#include "player.hh"

Player::Player(unsigned money, unsigned life_nb)
      : money_{money}, life_nb_{life_nb}
{
}

void Player::add_money(unsigned money)
{
    money_ += money;
}

bool Player::remove_money(unsigned money)
{
    return money_ >= money ? money_ -= money : false;
}

bool Player::remove_a_life()
{
    assert(!life_nb_);
    life_nb_--;
    return life_nb_ > 0;
}
