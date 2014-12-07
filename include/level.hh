#ifndef LEVEL_HH
# define LEVEL_HH

#include <string>

class Level
{
public:
    Level();
    Level(std::string path);

    bool make_mob();
private:
    std::string series_;
};

#endif /* !LEVEL_HH */
