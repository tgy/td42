#include <fstream>
#include <string>
#include <iostream>

#include "map_reader.hh"
#include "map.hh"

#define START 'S'
#define TOWER 'T'
#define EMPTY 'E'
#define FINNISH 'F'
#define OBSTACLE 'O'
#define B_OBSTACLE 'B'

bool MapReader::read_map(std::string file)
{
    std::string line;
    std::ifstream mapfile(file);
    if (mapfile.is_open())
    {
        unsigned x = 0;
        unsigned y = 0;
        while (getline(mapfile, line))
        {
            for (char& c : line)
            {
                switch (c)
                {
                    case START:
                        Map::cells[x][y].type = Empty;
                        Map::start_mobs.first = x;
                        Map::start_mobs.second = y;
                        break;
                    case TOWER:
                        Map::cells[x][y].type = Tower;
                        break;
                    case EMPTY:
                        Map::cells[x][y].type = Empty;
                        break;
                    case FINNISH:
                        Map::cells[x][y].type = Empty;
                        Map::finish_mobs.first = x;
                        Map::finish_mobs.second = y;
                        break;
                    case OBSTACLE:
                        Map::cells[x][y].type = Obstacle;
                        break;
                    case B_OBSTACLE:
                        Map::cells[x][y].type = Blocking_obstacle;
                        break;
                }
                x++;
            }
            y++;
        }
        Map::width = x;
        Map::height = y;
        mapfile.close();
        return true;
    }
    else
        return false;
}
