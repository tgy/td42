#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "settings.hh"
#include "map.hh"

//#define START "S"
#define TOWER "T"
#define EMPTY "E"
//#define FINNISH "F"
#define OBSTACLE "O"
#define B_OBSTACLE "B"

std::vector<std::vector<Cell>> Map::cells;
std::list<std::shared_ptr<Turret>> Map::turrets;
std::list<std::shared_ptr<Mob>> Map::ennemies;
std::pair<int, int> Map::start_mobs;
std::pair<int, int> Map::finish_mobs;
unsigned Settings::screen_width;
unsigned Settings::screen_height;
unsigned Map::width;
unsigned Map::height;

void Map::init(unsigned width, unsigned height)
{
    cells = std::vector<std::vector<Cell>>(width);

    for (unsigned i = 0; i < height; ++i)
        cells[i] = std::vector<Cell>(height);
}

int Map::cost(const std::pair<int, int>& start,
              const std::pair<int, int>& end)
{
    int cost = 0;
    if (cells[end.first][end.second].type == CellType::Empty)
        cost =  1;
    cost = 2;
    cost += cells[start.first][start.second].type != CellType::Empty;
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
        && cells[node.first][node.second].type == CellType::Empty;
}

void Map::print(std::ostream& out)
{
    for (const auto& line : cells)
    {
        for (const auto& cell : line)
            out << cell_to_str(cell.type) + " ";

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

void Map::init_draw(float x1, float y1, float x2, float y2)
{
    sf::Texture tile1;
    if (!tile1.loadFromFile("resources/logo.png"))
        throw std::logic_error("Could not load tile1.");
    auto tile_size = tile1.getSize();
    float tsize_x = (x2 - x1) / width;
    float tsize_y = (y2 - y1) / height;
    float scale_x = tsize_x / tile_size.x;
    float scale_y = tsize_y / tile_size.y;
    float pos_x = x1;
    std::cout << "Starting init. Map has size of " << width << "x" << height << std::endl;
    for (unsigned x = 0; x < width; ++x, pos_x += tsize_x)
    {
        float pos_y = y1;
        for (unsigned y = 0; y < height; ++y, pos_y += tsize_y)
        {
            std::cout << "Wrote Item at pos (" << pos_x << "," << pos_y << ")" << std::endl;
            sf::Sprite s(tile1);
            s.setPosition(pos_x, pos_y);
            s.setScale(scale_x, scale_y);
            cells[x][y].sprite = s;
        }
    }
}

void Map::draw(sf::RenderWindow& w)
{
    for (unsigned x = 0; x < width; ++x)
        for (unsigned y = 0; y < height; ++y)
            w.draw(cells[x][y].sprite);
    w.clear();
}
