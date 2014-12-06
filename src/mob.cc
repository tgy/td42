#include "mob.hh"

Mob::Mob(unsigned life, float x, float y, float direction, float speed,
         bool can_fly)
   : Entity(life, x, y, direction), speed_(speed), can_fly_(can_fly)
{
}
float Mob::get_speed()
{
  return this->speed_;
}
bool Mob::can_fly()
{
  return this->can_fly_;
}
