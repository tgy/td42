#include <memory>
#include <cfloat>

#include "map.hh"
#include "mob.hh"
#include "pathfinding.hh"

Mob::Mob(unsigned life, float x, float y, float direction, float speed,
         bool can_fly, unsigned fixed_res, unsigned reward, unsigned power,
         float range)
   : Entity(life, x, y, direction, fixed_res, power, range),
           can_fly_{can_fly}, reward_{reward}
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
    if (x_ == px && y_ == py)
    {
      path_.pop_front();
      if (path_.empty())
        return;
      next = *path_.begin();
    }
  }
}

void Mob::update_pathfinding()
{
  std::pair<int, int> t(this->x_, this->y_);
  this->path_ = pathfind(t, Map::finish_mobs);
}
