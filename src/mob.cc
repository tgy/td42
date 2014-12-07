#include <memory>
#include <cmath>
#include <cfloat>

#include "map.hh"
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
   : Entity(life, x, y, direction, fixed_res, power, range, off_x, off_y),
           can_fly_{can_fly}, reward_{reward}, old_x_{-1}, old_y_{-1}
{
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
        int px = x_;
        int py = y_;
        if ((x_ == px && y_ == py) || old_x_ == -1 || old_y_ == -1)
        {
            old_x_ = x_;
            old_y_ = y_;
            path_.pop_front();
            if (path_.empty())
                return;
            next = *path_.begin();
            float dx = next.first - x_;
            float dy = next.second - y_;
            float r = sqrt(dx * dx + dy * dy);
            direction_ = acos(dx / r);
        }
        float dx = (next.first - old_x_) * speed_;
        float dy = (next.second - old_y_) * speed_;
        x_ += dx;
        y_ += dy;
    }
}


void Mob::attack()
{
}

void Mob::update_pathfinding()
{
    this->path_.clear();
    return;
    std::pair<int, int> t(this->x_, this->y_);
    std::cout << "Starting from (" << t.first << "," <<  t.second << ")" << std::endl;
    std::cout << "We're going to (" << Map::finish_mobs.first << "," <<  Map::finish_mobs.second << ")" << std::endl;
    this->path_ = pathfind(t, Map::finish_mobs);
    old_x_ = -1;
    old_y_ = -1;
}
