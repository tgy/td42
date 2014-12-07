#include <cfloat>
#include <iostream>
#include <cmath>
#include "map.hh"
#include "turret.hh"
#include "turrets/basic.hh"
#include "turrets/sniper.hh"
#include "turrets/super.hh"

sf::Texture BasicTurret::basic_texture_;
char BasicTurret::initialized = 0;
sf::Texture SniperTurret::sniper_texture_;
char SniperTurret::initialized = 0;
sf::Texture SuperTurret::super_texture_;
char SuperTurret::initialized = 0;

Turret::Turret(unsigned life, float x, float y, float direction,
               unsigned recharge_time, unsigned fixed_res, unsigned power,
               float range, float off_x, float off_y, unsigned cost)
      : Entity(life, x, y, direction, power, range, fixed_res, off_x, off_y),
        recharge_time_(recharge_time), recharge_{0}, cost_{cost}, spy_{nullptr}
{
}

unsigned Turret::get_recharge_time()
{
    return this->recharge_time_;
}

void Turret::attack(unsigned elapsed_ms)
{
    if (recharge_ < 0)
        recharge_ = 0;
    if (spy_ != nullptr) // Check if we have to forget the current one
    {
        if (spy_->dead())
            spy_ = nullptr;
        else if (range_ < this->dist_from(*spy_)
                || !this->can_view(*spy_))
            spy_ = nullptr; // If Ennemy is too far... let's forget it.
    }
    if (spy_ == nullptr) // No ennemy... let's find one.
    {
        float dist = range_ + FLT_EPSILON;
        for (auto val : Map::ennemies)
        {
            float tdist = this->dist_from(*val);
            if (tdist < dist && this->can_view(*val))
            {
                dist = tdist;
                spy_ = val;
            }
        }
    }
    if (spy_ != nullptr)
    {
        if (recharge_ <= 0)
        {
            auto pos = spy_->get_pos();
            float dx = pos.first - this->x_;
            float dy = pos.second - this->y_;
            float r = sqrt(dx * dx + dy * dy);
            float normalized = dx / r;
            float angle = acos(normalized);
            this->direction_ = angle;
            spy_->take_attack(this->get_power());
            recharge_ += recharge_time_;
        }
        recharge_ -= elapsed_ms;
    }
}

void Turret::set_pos(unsigned x, unsigned y)
{
    x_ = x;
    y_ = y;
}
unsigned Turret::get_cost()
{
    return cost_;
}
