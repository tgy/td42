#include "entity.hh"

Entity::Entity(unsigned life, float x, float y, float direction,
               unsigned power, float range, unsigned fixed_res)
      : life_{life}, life_max_{life}, fixed_res_{fixed_res}, power_{power},
        x_{x}, y_{y}, direction_{direction}, range_(range)
{
}

float Entity::get_x()
{
  return this->x_;
}

float Entity::get_y()
{
  return this->y_;
}

float Entity::get_direction()
{
  return this->direction_;
}

unsigned Entity::get_life()
{
  return this->life_;
}

unsigned Entity::get_life_max()
{
  return this->life_max_;
}

unsigned Entity::get_power()
{
  return this->power_;
}

float Entity::get_range()
{
  return this->range_;
}

void Entity::take_attack(unsigned power)
{
  power -= this->fixed_res_;
  if (power >= this->life_)
    this->life_ = 0;
  else
    this->life_ -= power;
}
bool Entity::dead()
{
  return this->life_ == 0;
}

void Entity::attack()
{
}
