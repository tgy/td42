#ifndef MAP_HH
# define MAP_HH
# include <list>
# include <memory>
# include "mob.hh"
# include "turret.hh"

class Map
{
  public:
    std::list<std::shared_ptr<Mob>> ennemies;
    std::list<std::shared_ptr<Turret>> turrets;
};

#endif /* !MAP_HH */
