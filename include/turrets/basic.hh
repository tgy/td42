#ifndef BASIC_HH
# define BASIC_HH
# include <stdexcept>
# include <SFML/Graphics.hpp>
# include "map.hh"
# include "turret.hh"

class BasicTurret : public Turret
{
    public:
        static sf::Texture basic_texture_;
        static char initialized;
        BasicTurret(unsigned x, unsigned y)
            : Turret(10, x, y, 0, 100, 0, 10, 5, 0.05f, 0.25f)
        {
            if (initialized == 0)
            {
                if (!basic_texture_.loadFromFile("resources/tower1.png"))
                    initialized = 2;
                else
                    initialized = 1;
            }
            if (initialized != 1)
                throw std::logic_error("Could not load Basic Turret Img");
            texture_ = &basic_texture_;
            sf::Sprite s(basic_texture_);
            float w = Map::tile_w_ * 0.9f;
            auto pos = basic_texture_.getSize();
            float scale = w / pos.x;
            sprite_ = s;
            sprite_.setScale(scale, scale);
        }
};

#endif /* !BASIC_HH */
