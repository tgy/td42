#ifndef MAP_HH
# define MAP_HH

# include <list>
# include <vector>
# include <memory>
# include <SFML/Graphics.hpp>

# include "mob.hh"
# include "turret.hh"

enum CellType
{
    Empty,
    Tower,
    Obstacle,
    Blocking_obstacle
};
class Cell
{
    public:
        enum CellType type;
        sf::Sprite sprite;
};

class Map
{
    public:
        static std::list<std::shared_ptr<Mob>> ennemies;
        static std::list<std::shared_ptr<Turret>> turrets;

        static std::vector<std::vector<Cell>> cells;

        static void init(unsigned width, unsigned height);

        static std::list<std::pair<int, int>> neighbours(
                const std::pair<int, int>& pos);

        static int cost(const std::pair<int, int>& start,
                const std::pair<int, int>& end);

        static bool is_visitable(const std::pair<int, int>& node);

        static void print(std::ostream& out);

        static std::pair<int, int> start_mobs;
        static std::pair<int, int> finish_mobs;

        static unsigned width;
        static unsigned height;
        static void init_draw(float x1, float y1, float x2, float y2);
        static void draw(sf::RenderWindow& w);

    private:
        static std::string cell_to_str(CellType type);
};

#endif /* !MAP_HH */
