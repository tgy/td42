#ifndef MAP_READER_HH
# define MAP_READER_HH

#include <string>

class MapReader
{
    public:
        static bool set_size(std::string file);
        static bool read_map(std::string file);
};

#endif /* MAP_READER_HH */
