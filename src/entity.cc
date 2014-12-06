#include "entity.hh"

Entity::Entity(unsigned life, float x, float y, float direction,
               unsigned fixed_res)
      : life_{life}, life_max_{life},fixed_res_{fixed_res}, x_{x}, y_{y},
        direction_{direction}
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

void Entity::set_life(unsigned life)
{
  this->life_ = life > this->life_max_ ? this->life_max_ : life;
}
