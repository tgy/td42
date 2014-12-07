#ifndef SNIPER_HH
# define SNIPER_HH
# include <stdexcept>
# include "turret.hh"
# include "map.hh"

class SniperTurret : public Turret
{
    public:
        static sf::Texture sniper_texture_;
        static char initialized;
        SniperTurret(unsigned x, unsigned y)
            : Turret(20, x, y, 0, 300, 5, 15, 7, 0.05f, 0.25f)
        {
            if (initialized == 0)
            {
                if (!sniper_texture_.loadFromFile("resources/tower2.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load Sniper Turret Img");
            texture_ = &sniper_texture_;
            sf::Sprite s(sniper_texture_);
            float w = Map::tile_w_ * 0.9f;
            auto pos = sniper_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};


#endif /* !SNIPER_HH */
