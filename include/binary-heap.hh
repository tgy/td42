#ifndef BINARY_HEAP_HH
# define BINARY_HEAP_HH

#include <vector>
#include <algorithm>

template <typename TNode>
class BinaryHeap
{
public:
    void push(std::vector<TNode>& heap, const std::pair<int, int>& elt,
              int cost = 0)
    {
        this->table_.push_back(TNode(elt.first, elt.second, cost));
        std::push_heap(heap.begin(), heap.end());
    }

    TNode pop()
    {
        std::pop_heap(table_.begin(), table_.end());
        TNode node = table_.back();
        table_.pop_back();
        return node;
    }

    bool empty()
    {
        return table_.empty();
    }

private:
    bool nodecmp(const TNode& a, const TNode& b)
    {
        return b.cost < a.cost ? true : false;
    }

    std::vector<TNode> table_;
};

#endif /* !BINARY_HEAP_HH */
