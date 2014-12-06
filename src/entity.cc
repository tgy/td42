#include "entity.hh"

Entity::Entity(float x, float y, float direction)
      : x_{x}, y_{y}, direction_{direction}
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
