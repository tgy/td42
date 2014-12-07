#include <memory>
#include <cmath>
#include <cfloat>

#include "map.hh"
#include "player.hh"
#include "mob.hh"
#include "pathfinding.hh"
#include "mobs/foot_soldier.hh"
#include "mobs/horse_soldier.hh"
#include "mobs/tank_soldier.hh"

sf::Texture FootSoldier::foot_texture_;
char FootSoldier::initialized;
sf::Texture HorseSoldier::horse_texture_;
char HorseSoldier::initialized;
sf::Texture TankSoldier::tank_texture_;
char TankSoldier::initialized;

Mob::Mob(unsigned life, float x, float y, float direction, float speed,
         bool can_fly, unsigned fixed_res, unsigned reward, unsigned power,
         float range, float off_x, float off_y)
   : Entity(life, x, y, direction, power, range, fixed_res, off_x, off_y),
     can_fly_{can_fly}, reward_{reward}, old_x_{-1}, old_y_{-1}
{
    speed /= 300;
    if (speed <= 0 || speed >= 1)
        speed_ = 0.1f;
    else
        speed_ = speed;
    update_pathfinding();
}

float Mob::get_speed()
{
    return this->speed_;
}

bool Mob::can_fly()
{
    return this->can_fly_;
}

void Mob::move()
{
    if (!path_.empty())
    {
        std::pair<int, int> next = *path_.begin();
        if ((fabs(next.first - x_) < 0.1f && fabs(next.second - y_) < 0.1f)
            || old_x_ == -1 || old_y_ == -1)
        {
            old_x_ = next.first;
            old_y_ = next.second;
            path_.pop_front();
            if (path_.empty())
                return;
            next = *path_.begin();
        }
        float dx = (next.first - old_x_) * speed_;
        float dy = (next.second - old_y_) * speed_;
        x_ += dx;
        y_ += dy;
    }
}

void Mob::attack(unsigned elapsed_ms)
{
    ++elapsed_ms;
}

void Mob::harakiri()
{
    Player::add_money(reward_);
    life_ = 0;
}

void Mob::update_pathfinding()
{
    std::pair<int, int> curpos;
    curpos.first = x_;
    curpos.second = y_;
    if (!path_.empty())
        curpos = path_.front();
    this->path_.clear();
    std::pair<int, int> t(this->x_, this->y_);
    this->path_ = pathfind(t, Map::finish_mobs);
    path_.push_front(curpos);
}
