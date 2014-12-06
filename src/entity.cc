#include <cmath>
#include <SFML/Graphics.hpp>
#include <utility>
#include "entity.hh"

Entity::Entity(unsigned life, float x, float y, float direction,
               unsigned power, float range, unsigned fixed_res)
      : life_{life}, life_max_{life}, fixed_res_{fixed_res}, power_{power},
        x_{x}, y_{y}, direction_{direction}, range_{range}
{
}

std::pair<float, float> Entity::get_pos()
{
  return std::pair<float, float>(this->x_, this->y_);
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
  if (power <= this->fixed_res_)
    return;

  power -= this->fixed_res_;

  if (power >= this->life_)
    this->life_ = 0;
  else
    this->life_ -= power;

  if (this->life_ == 0)
    this->harakiri();
}

float Entity::dist_from(Entity &a)
{
  auto pos = a.get_pos();
  float dx = pos.first - x_;
  float dy = pos.second - y_;
  return sqrt(dx * dx + dy * dy);
}

bool Entity::dead()
{
  return this->life_ == 0;
}

void Entity::harakiri()
{
  this->life_ = 0;
}

bool Entity::can_view(Entity& ennemy)
{
    ennemy = ennemy;
    return true;
}

bool Entity::operator<(const Entity& e)
{
    if (e.y_ != y_)
        return y_ < e.y_;
    return x_ < e.x_;
}

void Entity::draw(sf::RenderWindow& w)
{
    w.clear();
}
