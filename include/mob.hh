#ifndef MOB_HH
# define MOB_HH
# include "entity.hh"

class Mob : public Entity
{
  public:
    Mob(unsigned life, float x, float y, float direction, float speed,
        bool can_fly);
    virtual ~Mob() = default;
    float get_speed();
    bool can_fly();
  protected:
    float speed_;
    bool can_fly_;
};

#endif /* !MOB_HH */
