#include <algorithm>

#include "map.hh"

//#define START "S"
#define TOWER "T"
#define EMPTY "E"
//#define FINNISH "F"
#define OBSTACLE "O"
#define B_OBSTACLE "B"

std::vector<std::vector<CellType>> Map::cells;
std::list<std::shared_ptr<Turret>> Map::turrets;
std::list<std::shared_ptr<Mob>> Map::ennemies;
std::pair<int, int> Map::start_mobs;
std::pair<int, int> Map::finish_mobs;
unsigned Map::width;
unsigned Map::height;

void Map::init(unsigned width, unsigned height)
{
    cells = std::vector<std::vector<CellType>>(width);

    for (unsigned i = 0; i < height; ++i)
        cells[i] = std::vector<CellType>(height);
}

int Map::cost(const std::pair<int, int>& start,
              const std::pair<int, int>& end)
{
    int cost = 0;
    if (cells[end.first][end.second] == CellType::Empty)
        cost =  1;
    cost = 2;
    cost += cells[start.first][start.second] != CellType::Empty;
    return cost;
}

std::list<std::pair<int, int>> Map::neighbours(
                      const std::pair<int, int>& pos)
{
    std::list<std::pair<int, int>> neighbours = {
        std::make_pair(pos.first + 1, pos.second),
        std::make_pair(pos.first + 1, pos.second + 1),
        std::make_pair(pos.first, pos.second + 1),
        std::make_pair(pos.first, pos.second + 1)
    };

    for (auto it = neighbours.begin(); it != neighbours.end(); ++it)
        if (!is_visitable(*it))
        {
            it = neighbours.erase(it);
            --it;
        }

    return neighbours;
}

bool Map::is_visitable(const std::pair<int, int>& node)
{
    return node.first >= 0
        && static_cast<unsigned long>(node.first) < cells.size()
        && node.second >= 0
        && static_cast<unsigned long>(node.second) < cells[0].size()
        && cells[node.first][node.second] == CellType::Empty;
}

void Map::print(std::ostream& out)
{
    for (const auto& line : cells)
    {
        for (const auto& cell : line)
            out << cell_to_str(cell) + " ";

        out << std::string("\n");
    }
}

std::string Map::cell_to_str(CellType type)
{
    switch (type)
    {
        case CellType::Tower:
            return TOWER;
        case CellType::Empty:
            return EMPTY;
        case CellType::Obstacle:
            return OBSTACLE;
        case CellType::Blocking_obstacle:
            return B_OBSTACLE;
        default:
            return "U";
    }
}

void Map::draw(sf::RenderWindow& w)
{
  w.clear();
}
