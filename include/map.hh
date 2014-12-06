#ifndef MAP_HH
# define MAP_HH

# include <list>
#include <vector>
# include <memory>

# include "mob.hh"
# include "turret.hh"

enum CellType
{
    Empty,
    Tower
};

class Map
{
public:
    static std::list<std::shared_ptr<Mob>> ennemies;
    static std::list<std::shared_ptr<Turret>> turrets;

    static std::vector<std::vector<CellType>> cells;

    static void init(unsigned width, unsigned height);

    static std::list<std::pair<int, int>> neighbours(
          const std::pair<int, int>& pos);

    static int cost(const std::pair<int, int>& start,
                    const std::pair<int, int>& end);

    static bool is_visitable(const std::pair<int, int>& node);

    static void print(std::ostream& out);

    static std::pair<int, int> start_mobs;
    static std::pair<int, int> finish_mobs;

private:
    static std::string cell_to_str(CellType type);
};

#endif /* !MAP_HH */
