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
    Empty = 0,
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

        static void init();

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
        static void init_draw(float x1, float y1);
        static void draw(sf::RenderWindow& w, std::shared_ptr<Turret> t);
        static void map_to_screen(float x, float y, float& rx, float &ry);
        static void screen_to_map(unsigned x, unsigned y,
                                  unsigned& rx, unsigned& ry);
        static float tile_w_;
        static float tile_h_;
    private:
        static float off_x_;
        static float off_y_;
        static std::string cell_to_str(CellType type);
        static std::vector<sf::Texture> textures_;
};

#endif /* !MAP_HH */
