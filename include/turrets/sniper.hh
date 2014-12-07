#ifndef SNIPER_HH
# define SNIPER_HH
# include "../turret.hh"

class SniperTurret : public Turret
{
    public:
        SniperTurret(unsigned x, unsigned y)
            : Turret(20, x, y, 0, 300, 5, 30, 3, 0, 0)
        {}
};


#endif /* !SNIPER_HH */
