#ifndef MOB_HH
# define MOB_HH
# include <list>
#include <utility>
# include "entity.hh"

class Mob : public Entity
{
    public:

        Mob(unsigned life, float x, float y, float direction, float speed,
            bool can_fly, unsigned reward,  unsigned fixed_res = 0,
            unsigned power = 0, float range = 0, float off_x = 0,
            float off_y = 0);
        virtual ~Mob() = default;
        float get_speed();
        bool can_fly();
        unsigned get_reward();
        void attack(unsigned elapsed_ms) override;
        void move();
        void update_pathfinding();

    protected:
        float speed_;
        bool can_fly_;
        unsigned reward_;
        std::list<std::pair<int, int>> path_;
        float old_x_;
        float old_y_;
};

#endif /* !MOB_HH */
