#ifndef MOUSE_HH
# define MOUSE_HH

#include <tuple>

class Mouse
{
    public:
        static std::pair<int, int> get_mous_pos();
};

#endif /* MOUSE_HH */
