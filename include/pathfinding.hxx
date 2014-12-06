#include <vector>
#include <algorithm>
#include <utility>

#include "pathfinding.hh"


template <typename TMap>
std::list<std::pair<int, int>> pathfind(const std::pair<int, int>& start,
                                        const std::pair<int, int>& end,
                                        const TMap& map)
{
    std::list<std::pair<int, int>> path;
    std::vector<Node> frontier;
    push_heap(start, 0);

    return path;
}
