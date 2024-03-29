#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "settings.hh"
#include "entity.hh"
#include "map.hh"

//#define START "S"
#define TOWER "T"
#define EMPTY "E"
//#define FINNISH "F"
#define OBSTACLE "O"
#define B_OBSTACLE "B"

std::vector<std::vector<Cell>> Map::cells;
std::vector<sf::Texture> Map::textures_;
std::list<std::shared_ptr<Turret>> Map::turrets;
std::list<std::shared_ptr<Mob>> Map::ennemies;
std::pair<int, int> Map::start_mobs;
std::pair<int, int> Map::finish_mobs;
unsigned Settings::screen_width;
unsigned Settings::screen_height;
unsigned Map::width;
unsigned Map::height;
float Map::off_x_;
float Map::off_y_;
float Map::tile_w_;
float Map::tile_h_;

void Map::init()
{
    ennemies.clear();
    turrets.clear();
    cells = std::vector<std::vector<Cell>>(width);

    for (unsigned i = 0; i < width; ++i)
    {
        cells[i] = std::vector<Cell>(height);
        for (unsigned j = 0; j < height; ++j)
            cells[i][j].type = CellType::Empty;
    }
}

int Map::cost(const std::pair<int, int>& start, const std::pair<int, int>& end)
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
    std::pair<int, int> tab[4] = {
        std::make_pair(pos.first + 1, pos.second),
        std::make_pair(pos.first - 1, pos.second),
        std::make_pair(pos.first, pos.second + 1),
        std::make_pair(pos.first, pos.second - 1)
    };
    std::list<std::pair<int, int>> neighbours;
    for (unsigned i = 0; i < 4; ++i)
        if (is_visitable(tab[i]))
        {
            if (rand() % 2)
                neighbours.push_back(tab[i]);
            else
                neighbours.push_front(tab[i]);
        }
    return neighbours;
}

bool Map::is_visitable(const std::pair<int, int>& node)
{
    return Map::is_in_bounds(node)
        && cells[node.first][node.second].type == CellType::Empty;
}

bool Map::is_in_bounds(const std::pair<int, int>& node)
{
    return node.first >= 0
        && static_cast<unsigned long>(node.first) < cells.size()
        && node.second >= 0
        && static_cast<unsigned long>(node.second) < cells[0].size();
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

void Map::init_draw(float x1, float y1)
{
    textures_ = std::vector<sf::Texture>(4);
    if (!textures_[Blocking_obstacle].loadFromFile("resources/tiles/block.png")
        || !textures_[Obstacle].loadFromFile("resources/tiles/obstacle.png")
        || !textures_[Empty].loadFromFile("resources/tiles/empty.png")
        || !textures_[Tower].loadFromFile("resources/tiles/empty.png"))
        throw std::logic_error("Could not load tile1.");
    float tsize_x = 60;
    float tsize_y = 40;
    float pos_x = x1;
    for (unsigned x = 0; x < width; ++x, pos_x += tsize_x)
    {
        float pos_y = y1;
        for (unsigned y = 0; y < height; ++y, pos_y += tsize_y)
        {
            auto tile_size = textures_[cells[x][y].type].getSize();
            float scale_x = tsize_x / tile_size.x;
            float scale_y = tsize_y / tile_size.y;
            sf::Sprite s(textures_[cells[x][y].type]);
            cells[x][y].sprite = s;
            cells[x][y].sprite.setPosition(pos_x, pos_y);
            cells[x][y].sprite.setScale(scale_x, scale_y);
        }
    }
    off_x_ = x1;
    off_y_ = y1;
    tile_w_ = tsize_x;
    tile_h_ = tsize_y;
}

static bool entities_compare(std::shared_ptr<Entity> a,
                             std::shared_ptr<Entity> b)
{
    return b->get_pos().second - a->get_pos().second > 0.0001f;
}

void Map::draw(sf::RenderWindow& w, std::shared_ptr<Turret> t)
{
    for (unsigned x = 0; x < width; ++x)
        for (unsigned y = 0; y < height; ++y)
            w.draw(cells[x][y].sprite);
    Map::ennemies.sort();
    Map::turrets.sort();
    std::vector<std::shared_ptr<Entity>> entities;
    entities.insert(entities.end(), Map::ennemies.begin(), Map::ennemies.end());
    entities.insert(entities.end(), Map::turrets.begin(), Map::turrets.end());
    std::sort(entities.begin(), entities.end(), entities_compare);

    for (const auto& entity : entities)
        entity->draw(w);
    if (t != nullptr)
        t->draw(w);
}

void Map::map_to_screen(float x, float y, float& rx, float &ry)
{
    rx = off_x_ + x * tile_w_;
    ry = off_y_ + y * tile_h_;
}

void Map::screen_to_map(unsigned x, unsigned y, unsigned& rx, unsigned& ry)
{
    rx = (x - Map::off_x_) / Map::tile_w_;
    ry = (y - Map::off_y_) / Map::tile_h_;
}
