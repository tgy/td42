#include <algorithm>

#include "map.hh"

int Map::cost(const std::pair<int, int>& start,
              const std::pair<int, int>& end) const
{
    int cost = 0;
    if (cells[end.first][end.second] == CellType::Empty)
        cost =  1;
    cost = 2;
    cost += cells[start.first][start.second] != CellType::Empty;
    return cost;
}

std::list<std::pair<int, int>> Map::neighbours(
                      const std::pair<int, int>& pos) const
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

bool Map::is_visitable(const std::pair<int, int>& node) const
{
    return node.first >= 0
        && static_cast<unsigned long>(node.first) < cells.size()
        && node.second >= 0
        && static_cast<unsigned long>(node.second) < cells[0].size()
        && cells[node.first][node.second] == CellType::Empty;
}

