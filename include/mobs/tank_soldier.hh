#ifndef TANK_SOLDIER_HH
# define TANK_SOLDIER_HH

# include <stdexcept>
# include <SFML/Graphics.hpp>
# include "map.hh"
# include "turret.hh"

class TankSoldier : public Mob
{
    public:
        static sf::Texture tank_texture_;
        static char initialized;
        TankSoldier(unsigned x, unsigned y)
            : Mob(20, x, y, 0, 5, 0, 10, 25, 0, 0, -0.1f, 0.25f)
        {
            if (initialized == 0)
            {
                if (!tank_texture_.loadFromFile("resources/unit3.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load tank Soldier Img");
            texture_ = &tank_texture_;
            sf::Sprite s(tank_texture_);
            float w = Map::tile_w_ * 1.3f;
            auto pos = tank_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};


#endif /* !TANK_SOLDIER_HH */
