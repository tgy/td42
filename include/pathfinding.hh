#ifndef PATHFINDING_HH
# define PATHFINDING_HH

#include <list>

template <typename TMap, typename TNode>
std::list<TNode> pathfind(const TNode& start, const TNode& end);

struct Node
{
    Node(int x, int y, int cost = 0) : x(x), y(y), cost(cost)
    {}

    int x;
    int y;
    int cost;
};

#include "pathfinding.hxx"

#endif /* !PATHFINDING_HH */
