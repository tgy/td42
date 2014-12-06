#ifndef TURRET_HH
# define TURRET_HH
# include <memory>
# include "entity.hh"

class Turret : public Entity
{
  public:
    Turret(unsigned life, float x, float y, float direction,
        unsigned recharge_time, unsigned fixed_res = 0, unsigned power = 0,
        float range = 0, float off_x = 0, float off_y = 0);
    virtual ~Turret() = default;
    void attack() override;
    unsigned get_recharge_time();
  protected:
    unsigned recharge_time_;
    std::shared_ptr<Entity> spy_;
};


#endif /* !TURRET_HH */
