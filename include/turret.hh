#ifndef TURRET_HH
# define TURRET_HH
# include <memory>
# include "entity.hh"

class Turret : public Entity
{
    public:
        Turret(unsigned life, float x, float y, float direction,
               unsigned recharge_time, unsigned fixed_res = 0,
               unsigned power = 0, float range = 0, float off_x = 0,
               float off_y = 0, unsigned cost = 0);
        virtual ~Turret() = default;
        void attack(unsigned elapsed_ms) override;
        unsigned get_recharge_time();
        void set_pos(unsigned x, unsigned y);
        unsigned get_cost();
    protected:
        unsigned recharge_time_;
        int recharge_;
        unsigned cost_;
        std::shared_ptr<Entity> spy_;
};


#endif /* !TURRET_HH */
