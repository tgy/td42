#ifndef SUPER_HH
# define SUPER_HH

# include "../turret.hh"

class SuperTurret : public Turret
{
    SuperTurret(unsigned x, unsigned y)
        : Turret(50, x, y, 0, 300, 5, 30, 3, 0, 0)
    {}
};


#endif /* !SUPER_HH */
