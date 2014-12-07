#ifndef BASIC_HH
# define BASIC_HH
# include <stdexcept>
# include "../turret.hh"

class BasicTurret : public Turret
{
    public:
        static sf::Texture basic_texture_;
        static char initialized;
        BasicTurret(unsigned x, unsigned y)
            : Turret(10, x, y, 0, 100, 0, 10, 3, 0, 0)
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
            sprite_ = s;
        }
};

#endif /* !BASIC_HH */
