#include <vector>
#include <iostream>
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

bool operator<(const PathNode& a, const PathNode& b)
{
    return a.cost > b.cost;
}

list<pair<int, int>> pathfind(const pair<int, int>& start,
                              const pair<int, int>& end)
{
    if (!Map::is_in_bounds(start) || !Map::is_in_bounds(end))
        return {};
    priority_queue<PathNode> frontier;
    frontier.push(PathNode(start, 0));
    std::map<pair<int, int>, pair<int, int>> came_from;
    std::map<pair<int, int>, int> costs;
    came_from[start] = start;
    costs[start] = 0;

    while (not frontier.empty())
    {
        PathNode current = frontier.top();
        frontier.pop();
        if (current.cell == end)
            break;
        for (const auto& next : Map::neighbours(current.cell))
        {
            int new_cost = costs[current.cell] + Map::cost(current.cell, next);
            if (costs.count(next) == 0 || new_cost < costs[next])
            {
                costs[next] = new_cost;
                frontier.push(PathNode(next, new_cost));
                came_from[next] = current.cell;
            }
        }
    }

    if (came_from.find(end) == came_from.end())
        return {};

    pair<int, int> current = end;
    list<pair<int, int>> path = { current };

    while (current != start)
    {
        current = came_from[current];
        path.push_front(current);
    }

    return path;
}
