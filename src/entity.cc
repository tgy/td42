#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
#include "map.hh"
#include "entity.hh"

Entity::Entity(unsigned life, float x, float y, float direction,
               unsigned power, float range, unsigned fixed_res, float off_x,
               float off_y)
      : life_{life}, life_max_{life}, fixed_res_{fixed_res}, power_{power},
        x_{x}, y_{y}, off_x_{off_x}, off_y_{off_y}, direction_{direction},
        range_{range}, texture_{nullptr}, color_{sf::Color(255, 255, 255, 255)}
{
}

std::pair<float, float> Entity::get_pos() const
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
    std::cout << "Attaque: " << power << " rf: " << fixed_res_ << std::endl;
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
    float r = sqrt(dx * dx + dy * dy);
    return r;
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
    if (texture_ == nullptr)
        return;
    float px;
    float py;
    Map::map_to_screen(x_ + 0.5f, y_ + 0.5f, px, py);
    px += off_x_ * Map::tile_w_;
    py += off_y_ * Map::tile_h_;
    auto pos = texture_->getSize();
    auto scale = sprite_.getScale();
    pos.x *= scale.x;
    pos.y *= scale.y;
    sprite_.setPosition(px - pos.x / 2, py - pos.y);
    w.draw(sprite_);
}

void Entity::set_opacity(unsigned char alpha)
{
    color_.a  = alpha;
    sprite_.setColor(color_);
}
