#include <memory>
#include <iostream>
#include <stdexcept>
#include "gamestates/playstate.hh"
#include "gamestates/startstate.hh"
#include "gamestates/playstate.hh"

StartState::StartState()
    : logo_load_time_{1000}, logo_size_{0}, logo_final_size_{0.8},
    logo_x_{0}, logo_y_{0}, wait_time_{1000}
{
    if (!logo_.loadFromFile("resources/logo.png"))
        throw std::logic_error("Could not load logo.");
    sf::Sprite s(logo_);
    logo_sprite_ = s;
    logo_sprite_.setPosition(logo_x_, logo_y_);
    logo_sprite_.setScale(logo_size_, logo_size_);
}

void StartState::draw(sf::RenderWindow& w)
{
    w.draw(logo_sprite_);
}


void StartState::update(unsigned elapsed_ms)
{
    // Initialisation of
    if (logo_size_ < logo_final_size_)
    {
        logo_size_ += logo_final_size_ * elapsed_ms / logo_load_time_;
        if (logo_size_ > logo_final_size_)
            logo_size_ = logo_final_size_;
    }
    else
        wait_time_ -= elapsed_ms;
    auto vect = logo_.getSize();
    float x = logo_x_ + (1 - logo_size_) * vect.x / 2;
    float y = logo_y_ + (1 - logo_size_) * vect.y / 2;
    logo_sprite_.setPosition(x, y);
    logo_sprite_.setScale(logo_size_, logo_size_);
    if (wait_time_ <= 0)
    {
        std::string default_map_path = "resources/map0.td42";
        std::string map_path;
        std::cout << "Enter map path (defaults to 'resources/map0.td42')";
        getline(std::cin, map_path);
        GameState::stack.pop_back();
        GameState::stack.push_back(std::make_shared<PlayState>(
            map_path.length() > 0 ? map_path : default_map_path));
    }
}
