#include "turret.hh"

Turret::Turret(unsigned life, float x, float y, float direction,
               unsigned recharge_time, unsigned fixed_res, unsigned power,
               float range)
   : Entity(life, x, y, direction, fixed_res, power, range),
   recharge_time_(recharge_time)
{
}

unsigned Turret::get_recharge_time()
{
  return this->recharge_time_;
}

