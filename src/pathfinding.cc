#include <vector>
#include <queue>
#include <memory>
#include <map>
#include <algorithm>
#include <list>

#include "map.hh"
#include "pathfinding.hh"

using std::pair;
using std::list;
using std::priority_queue;

list<pair<int, int>> pathfind(const pair<int, int>& start,
                              const pair<int, int>& end,
                              const Map& map)
{
    priority_queue<PathNode> frontier;
    frontier.push(PathNode(start, 0));
    std::map<pair<int, int>, std::shared_ptr<pair<int, int>>> came_from;
    std::map<pair<int, int>, int> costs;
    came_from[start] = nullptr;
    costs[start] = 0;

    while (not frontier.empty())
    {
        PathNode current = frontier.top();
        frontier.pop();
        if (current.cell == end)
            break;
        for (const auto& next : map.neighbours(current.cell))
        {
            int new_cost = costs[current.cell] + map.cost(current.cell, next);
            if (costs.count(next) == 0 || new_cost < costs[next])
            {
                costs[next] = new_cost;
                frontier.push(PathNode(next, new_cost));
                came_from[next] = std::make_shared<PathNode>(current);
            }
        }
    }

    //return path;
}
