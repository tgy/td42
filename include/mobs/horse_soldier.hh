#ifndef HORSE_SOLDIER_HH
# define HORSE_SOLDIER_HH

# include <stdexcept>
# include <SFML/Graphics.hpp>
# include "map.hh"
# include "turret.hh"

class HorseSoldier : public Mob
{
    public:
        static sf::Texture horse_texture_;
        static char initialized;
        HorseSoldier(unsigned x, unsigned y)
            : Mob(20, x, y, 0, 20, 0, 3, 10, 0, 0, -0.07f, 0.25f)
        {
            if (initialized == 0)
            {
                if (!horse_texture_.loadFromFile("resources/unit2.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load Horse Soldier Img");
            texture_ = &horse_texture_;
            sf::Sprite s(horse_texture_);
            float w = Map::tile_w_ * 1.3f;
            auto pos = horse_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};


#endif /* !HORSE_SOLDIER_HH */
