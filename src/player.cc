#include <cassert> //remove_a_life()

#include "player.hh"

unsigned Player::money_;
unsigned Player::life_nb_;
std::chrono::time_point<std::chrono::system_clock> Player::start_time_;

void Player::init(unsigned money, unsigned life_nb,
                  std::chrono::time_point<std::chrono::system_clock> start_time)
{
    money_ = money;
    life_nb_ = life_nb;
    start_time_ = start_time;
}

void Player::add_money(unsigned money)
{
    money_ += money;
}

bool Player::remove_money(unsigned money)
{
    return money_ >= money ? money_ -= money : false;
}

unsigned Player::get_life_nb()
{
    return life_nb_;
}

unsigned Player::get_money()
{
    return money_;
}

std::chrono::time_point<std::chrono::system_clock> Player::get_start_time()
{
    return start_time_;
}

bool Player::remove_a_life()
{
    assert(!life_nb_);
    life_nb_--;
    return life_nb_ > 0;
}
