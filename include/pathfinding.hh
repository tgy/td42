#ifndef PATHFINDING_HH
# define PATHFINDING_HH

#include <list>
#include <utility>

class Map;

std::list<std::pair<int, int>> pathfind(const std::pair<int, int>& start,
                                        const std::pair<int, int>& end);

struct PathNode
{
    PathNode(const std::pair<int, int>& cell, int cost = 0)
        : cell(cell), cost(cost)
    {}

    std::pair<int, int> cell;
    int cost;
};

#endif /* !PATHFINDING_HH */
