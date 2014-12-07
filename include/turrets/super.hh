#ifndef SUPER_HH
# define SUPER_HH

# include <stdexcept>
# include "map.hh"
# include "turret.hh"

class SuperTurret : public Turret
{
    public:
        static sf::Texture super_texture_;
        static char initialized;
        SuperTurret(unsigned x, unsigned y)
            : Turret(50, x, y, 0, 300, 5, 30, 3, 0.05f, 0.40f)
        {
            if (initialized == 0)
            {
                if (!super_texture_.loadFromFile("resources/tower4.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load Sniper Turret Img");
            texture_ = &super_texture_;
            sf::Sprite s(super_texture_);
            float w = Map::tile_w_ * 1.5f;
            auto pos = super_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};


#endif /* !SUPER_HH */
