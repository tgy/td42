#ifndef FOOT_SOLDIER_HH
# define FOOT_SOLDIER_HH

# include <stdexcept>
# include <iostream>
# include <SFML/Graphics.hpp>
# include "map.hh"
# include "turret.hh"

class FootSoldier : public Mob
{
    public:
        static sf::Texture foot_texture_;
        static char initialized;
        FootSoldier(unsigned x, unsigned y)
            : Mob(20, x, y, 0, 10, 0, 0, 100, 0, 0, -0.07f, 0.25f)
        {
            if (initialized == 0)
            {
                if (!foot_texture_.loadFromFile("resources/unit1.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load foot soldier Img");
            texture_ = &foot_texture_;
            sf::Sprite s(foot_texture_);
            float w = Map::tile_w_ * 1.3f;
            auto pos = foot_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};


#endif /* !FOOT_SOLDIER_HH */
